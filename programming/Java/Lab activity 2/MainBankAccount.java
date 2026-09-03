package ACTIBATERBONITY;

import java.util.Scanner;

public class MainBankAccount {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter Account Number: ");
		String accountNumber = input.nextLine();
		
		System.out.print("Enter Account Name: ");
		String accountName = input.nextLine();
		
		System.out.print("Enter Initial Balance: ");
		double balance = input.nextDouble();
		
		BankAccount account = new BankAccount(
				accountNumber,
				accountName,
				balance
		);
		
		System.out.print("Enter Deposit Amount: ");
		double depositAmount = input.nextDouble();
		account.deposit(depositAmount);
		
		System.out.print("\nEnter Withdrawal Amount: ");
		double withdrawAmount = input.nextDouble();
		account.withdraw(withdrawAmount);
		
		account.displayAccountInfo();
		
		input.close();
	}
}
