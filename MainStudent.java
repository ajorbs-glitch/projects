package ACTIBATERBONITY;

import java.util.Scanner;

public class MainStudent {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter Student Name: ");
		String name = input.nextLine();
		
		System.out.print("Enter Prelim Grade: ");
		float prelim = input.nextFloat();
		
		System.out.print("Enter Midterm Grade: ");
		float midterm = input.nextFloat();
		
		System.out.print("Enter Final Grade: ");
		float finalGrade = input.nextFloat();
		
		Student student = new Student(name, prelim, midterm, finalGrade);
		
		student.displayStudentInfo();
		
		input.close();
		
	}
}
