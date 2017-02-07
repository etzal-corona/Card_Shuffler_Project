//Etzal Corona
//ME 493 HW 1
// Buddy Coded with Robert Roque and Roberto Jimenez

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <assert.h>

using namespace std;



class Cards {

public:

	int face;
	int suit;

	Cards();

	Cards(int face, int suit) {
		this->face = face;
		this->suit = suit;

	}

	void printCard(Cards newCard, int& suit, int& face) {

		suit = newCard.suit;
		face = newCard.face;

		//cout << "Suit:" << newCard.suit << " Value:" << newCard.face << endl;
	}


};







// Constructor Does Not Do Anything
Cards::Cards()
{
}


class Deck {

private:
	// create a vector of cards to create a playing deck
	vector<Cards> deck;


public:

	// constructor to create deck
	Deck();

	// combine decks
	Deck Deck::operator+(const Deck& other);

	// print all values of a deck
	void printDeck(int numberOfDecks);

	// print to file
	void printToFile(int numberOfDecks);

	// shuffle the deck
	void shuffle(int numberOfDecks);


};






//constructor to create deck - called every time a deck object is created
Deck::Deck()

{

	// four suits and 13 facecards per suit
	int numOfSuits = 4;
	int numOfFaceCards = 14;

	// variable for loop
	int innerIndex;
	int outerIndex;

	// nested four loop that fills up the deck with values and suits
	for (innerIndex = 1; innerIndex < numOfFaceCards; innerIndex++) {

		for (outerIndex = 0; outerIndex < numOfSuits; outerIndex++) {

			// create a card object 
			Cards card(innerIndex, outerIndex);

			// add that card to the deck
			deck.push_back(card);

		}


	}

}






Deck Deck::operator+(const Deck & other)
{
	// variable for number of cards in a deck
	int total = 52;


	// for loop to combine decks into a single deck
	for (int i = 0; i < total; i++) {

		// add cards from the other deck into the main deck
		this->deck.push_back(other.deck[i]);

	}


	return Deck();
}







// print contents of deck to screen
void Deck::printDeck(int numberOfDecks)
{

	// variables for number of cards
	int cardsInADeck = 52;
	int totalCards = cardsInADeck * numberOfDecks;

	// variables to hold face and suit
	int tempSuit;
	int tempFace;

	// variable for loop
	int index;

	// loop through all cards in the deck
	for (index = 0; index < totalCards; index++) {

		// create a card object
		Cards card;

		// pass a card to print its value
		card.printCard(deck[index], tempSuit, tempFace);

		// print out values
		cout << "Suit:" << tempSuit << " Value:" << tempFace << endl;
	}

}




// print contents of a deck to a file

void Deck::printToFile(int numberOfDecks) 

{

	// open file
	ofstream myfile;
	myfile.open("deckOutput.txt");

	// variables for number of cards
	int cardsInADeck = 52;
	int totalCards = cardsInADeck * numberOfDecks;

	// variables to hold face and suit
	int tempSuit;
	int tempFace;

	// variable for loop
	int index;

	// loop through all cards in the deck
	for (index = 0; index < totalCards; index++) {

		// create a card object
		Cards card;

		// pass a card to print its value
		card.printCard(deck[index], tempSuit, tempFace);

		myfile << "Suit:" << tempSuit << " Value:" << tempFace << endl;
	}

	// close file
	myfile.close();

}




// shufle the deck
void Deck::shuffle(int numberOfDecks) {

	// variables for holding the random card
	int randomCard;
	Cards holder;

	// variables for cards in deck
	int cardsInADeck = 52;
	int totalCards = cardsInADeck * numberOfDecks;

	// for loop to shuffle deck, switches one card with another RANDOM card in the deck,
	// effectively shuffling the deck
	for (int i = 0; i < totalCards; i++) {

		// choose any random card int the deck
		randomCard = rand() % totalCards;
		// and switch/swap the current card with the random card
		holder = deck[randomCard];
		deck[randomCard] = deck[i];
		deck[i] = holder;
	}


}



void TestA(vector <Cards> deck) {
	for (int x = 0; x < 52; x++) {
		for (int y = 0; y < 52; y++) {
			if (x == y) {
				assert(x == y); 
			}
			else if ((deck.at(x).suit == deck.at(y).suit) && (deck.at(x).face == deck.at(y).face)) {
					cout << "Test A Failed" << endl;
			}
		}
	}
} 


/*
void TestB(vector <Cards> deck) {
	int z=0; {
		for (int z = 0; z < 52; z++) {
			if ((deck.at(z).suit) == (deck.at(z).suit);	}
		z++
			cout << "Test B running" << endl;
		cout << z << "How many iterations of the first card in the combined decks" << endl;

}
	*/

int main() {
	
	vector <Cards> deck;
//	vector <Cards>* Deck;

	// number of cards
	int deckSize = 52;

	// total number of decks to shuffle, changing this variable will change the number of decks we will work with
	const int TOTAL_DECKS = 1;


	//Test A
	if (TOTAL_DECKS == 1) {
		//TestA(deck);
		cout << "Ran Test A" << endl;
	}
	else {
		cout << "Number of deck is not one" << endl;
	}
	


	// create our decks, using an array of deck objects
	Deck newDeck[TOTAL_DECKS];

	//newDeck[0].printDeck(1);

	// if only one deck
	if (TOTAL_DECKS == 1) {

		// shuffle
		newDeck[0].shuffle(TOTAL_DECKS);

		// print to file
		newDeck[0].printToFile(TOTAL_DECKS);
	}
	else {  // there is more than one deck

			// combine all the decks into a single deck;
		for (int index = 1; index < TOTAL_DECKS; index++) {

			// call method to combine multiple decks
			newDeck[0].operator+(newDeck[index]);
		}

		// shuffle the deck
		newDeck[0].shuffle(TOTAL_DECKS);

		// print to file
		newDeck[0].printToFile(TOTAL_DECKS);

	}
	// end program
	
	
	
	return 0;
}
