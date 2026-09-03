package ACTIBATERBONITY;

import java.util.Scanner;

public class MainProduct {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter Product Name: ");
		String productName = input.nextLine();
		
		System.out.print("Enter Price: ");
		double price = input.nextDouble();
		
		System.out.print("Enter Quantity: ");
		int quantity = input.nextInt();
		
		Product product = new Product(
				productName,
				price,
				quantity
		);
		
		product.displayOrder();
		
		
		input.close();
	}
}
