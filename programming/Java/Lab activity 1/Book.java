package labAct1;

public class Book {
	String title;
	String author;
	String genre;
	int pubYear;
	double price;
	
	Book(String title, String author, String genre, int pubYear, double price) {
		this.title = title;
		this.author = author;
		this.genre = genre;
		this.pubYear = pubYear;
		this.price = price;
	}
	
	void applyDiscount(double discount) {
		price = price - (price * discount / 100);
		System.out.println("Discount applied: " + discount + "%");
		System.out.println("New Price: " + price);
		System.out.println();
	}
	
	void displayInfo() {
		System.out.println("Genre: " + genre);
		System.out.println("Author: " + author);
		System.out.println("Year of Publication: " + pubYear);
		System.out.println("Price: " + price);
	
	}

}

