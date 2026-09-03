package ACTIBATERBONITY;

public class Student {
	
	private String name; 
	private float prelim;
	private float midterm;
	private float finalGrade;
	
	public Student(String name, float prelim, float midterm, float finalGrade) {
		this.name = name;
		this.prelim = prelim;
		this.midterm = midterm;
		this.finalGrade = finalGrade;
	}
	
	public double calculateAverage() {
		return (prelim + midterm + finalGrade) / 3;
	}
	
	public String getStatus() {
		if (calculateAverage() >= 75) {
			return "PASSED";
		} else {
			return "FAILED";
		}
	}
	
	public String getLetterGrade() {
		double average = calculateAverage();
		
		if (average >= 95) {
			return "A";
		} else if (average >= 90) {
			return "A-";
		} else if (average >= 80) {
			return "B";
		} else if (average >= 75) {
			return "C";
		} else {
			return "F";
		}
	}
	
	public void displayStudentInfo() {
		System.out.println("\nStudent Name: " + name);
		System.out.printf("Average: %.2f%n", calculateAverage());
		System.out.println("Status: " + getStatus());
		System.out.println("Letter Grade: " + getLetterGrade());
	}
	
}
