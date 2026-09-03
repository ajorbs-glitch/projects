package ACTIBATERBONITY;

public class Product {
	private String productName;
	private double price;
	private int quantity;
	
	public Product(String productName, double price, int quantity) {
		this.productName = productName;
		this.price = price;
		this.quantity = quantity;
	}
	
	public double calculateTotal() {
		return price * quantity;
	}
	
	public double calculateDiscount() {
		double total = calculateTotal();
		
		if (total >= 10000) {
			return total * 0.20;
		} 
		else if (total >= 9999) {
			return total * 0.15;
		} 
		else if (total >= 4999) {
			return total * 0.10;
		}
		else {
			return 0;
		}
	}
	
	public double calculateFinalAmount() {
		return calculateTotal() - calculateDiscount();
	}
	
	public void displayOrder() {
		System.out.println("\nProduct: " + productName);
		System.out.printf("Price: %.2f%n", price);
		System.out.println("Quantity: " + quantity);
		System.out.printf("Total: %.2f%n", calculateTotal());
		System.out.printf("Discount: %.2f%n", calculateDiscount());
		System.out.printf("Final Amount: %.2f%n", calculateFinalAmount());
		
	}
}
