#include <iostream>
#include <string>

using namespace std;

struct Song {
    string title;
    string producer;
    string singer;
    string genre;
    Song* next_song;
    Song* prev_song;

    Song(string t, string p, string s, string g) : title(t), producer(p), singer(s), genre(g), next_song(nullptr), prev_song(nullptr) {}
};

void addSong(Song*& head, string title, string producer, string singer, string genre) {
    Song* newSong = new Song(title, producer, singer, genre);

    if (!head) {
        head = newSong;
    } else {
        Song* currentSong = head;
        while (currentSong->next_song) {
            currentSong = currentSong->next_song;
        }
        currentSong->next_song = newSong;
        newSong->prev_song = currentSong;
    }
}

void displayByProducer(Song* head, string producer) {
    Song* currentSong = head;
    while (currentSong) {
        if (currentSong->producer == producer) {
            cout << "Title: " << currentSong->title << ", Singer: " << currentSong->singer << ", Genre: " << currentSong->genre << endl;
        }
        currentSong = currentSong->next_song;
    }
}

void displayBySinger(Song* head, string singer) {
    Song* currentSong = head;
    while (currentSong) {
        if (currentSong->singer == singer) {
            cout << "Title: " << currentSong->title << ", Producer: " << currentSong->producer << ", Genre: " << currentSong->genre << endl;
        }
        currentSong = currentSong->next_song;
    }
}

void displayByGenre(Song* head, string genre) {
    Song* currentSong = head;
    while (currentSong) {
        if (currentSong->genre == genre) {
            cout << "Title: " << currentSong->title << ", Producer: " << currentSong->producer << ", Singer: " << currentSong->singer << endl;
        }
        currentSong = currentSong->next_song;
    }
}

void displayPlaylist(Song* head) {
    Song* currentSong = head;
    while (currentSong) {
        cout << "Title: " << currentSong->title << ", Producer: " << currentSong->producer << ", Singer: " << currentSong->singer << ", Genre: " << currentSong->genre << endl;
        currentSong = currentSong->next_song;
    }
}

int main() {
    Song* playlist = nullptr;
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Song" << endl;
        cout << "2. Display by Producer" << endl;
        cout << "3. Display by Singer" << endl;
        cout << "4. Display by Genre" << endl;
        cout << "5. Display Entire Playlist" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, producer, singer, genre;
                cout << "Enter song title: ";
                cin>>title;
                cout << "Enter producer: ";
                cin>>producer;
                cout << "Enter singer: ";
                cin>>singer;
                cout << "Enter genre: ";
                cin>>genre;
                addSong(playlist, title, producer, singer, genre);
                break;
            }
            case 2: {
                string producer;
                cout << "Enter producer to display songs: ";
                cin>>producer;
                displayByProducer(playlist, producer);
                break;
            }
            case 3: {
                string singer;
                cout << "Enter singer to display songs: ";
                cin>>singer;
                displayBySinger(playlist, singer);
                break;
            }
            case 4: {
                string genre;
                cout << "Enter genre to display songs: ";
                cin>>genre;
                displayByGenre(playlist, genre);
                break;
            }
            case 5:
                cout << "Displaying entire playlist:" << endl;
                displayPlaylist(playlist);
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}