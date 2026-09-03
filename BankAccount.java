package ACTIBATERBONITY;

public class BankAccount {
	private String accountNumber;
	private String accountName;
	private double balance;
	
	public BankAccount(String accountNumber, String accountName, double balance) {
		this.accountNumber = accountNumber;
		this.accountName = accountName;
		this.balance = balance;
	}
	
	public void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			System.out.println("Deposit successful.");
		} else {
			System.out.println("Invalid deposit. Please input positive amount.");
		}
	}
	
	public void withdraw(double amount) {
		if (amount < balance) {
			balance -= amount;
			System.out.println("Withdrawal Successful.");
		} else {
			System.out.println("Insufficient Balance.");
		}
	}
	
	public void displayAccountInfo() {
		System.out.println("\nAccount Number: " + accountNumber);
		System.out.println("Account Name: " + accountName);
		System.out.printf("Remaining Balance: %.2f%n", balance);
	} 
	
	public double checkBalance() {
		return balance;
	}
	
}
