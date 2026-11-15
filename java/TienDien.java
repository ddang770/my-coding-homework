import java.util.Scanner;
import java.util.InputMismatchException;
public class TienDien {
	public static double tinhTien(int sodien){
		double tien = 0;
		if(sodien>100){
			tien = 50*1800 + 50*2200 + (sodien-100)*3000;
		} else if (sodien>50) {
			tien = 50*1800 + (sodien-50)*2200;
		} else {
			tien = sodien*1800;
		}
		return tien;
	}

	public static String mucTieuThu(int sodien){
		if(sodien<=50){
			return "Tiet kiem";
		} else if (sodien<=150) {
			return "Binh thuong";
		} else {
			return "Cao";
		}
	}

	public static void main(){
		Scanner sc = new Scanner(System.in);
		System.out.print("nhap ten kh: ");
		String name = sc.nextLine();
		int socu, somoi, sodien;
		try {
			do {
				System.out.print("nhap so cu: ");
				socu = sc.nextInt();
				System.out.print("nhap so moi: ");
				somoi = sc.nextInt();
				if (socu>somoi){
					System.out.println("Loi: so cu phai < so moi");
					System.out.println("Nhap lai!");
				}
			} while (socu>somoi);
		} catch(InputMismatchException e) {
			System.out.println("vui long nhap so nguyen");
			return;
		}

		sodien = somoi-socu;
		double tien = tinhTien(sodien);
		double thueVAT = tien * 10/100;

		System.out.println("\n HOA DON TIEN DIEN ");
		System.out.println("khach hang: " + name);
		System.out.println("so dien tieu thu: "+ sodien);
		System.out.println("tien dien: "+ tien);
		System.out.println("thue VAT 10%: "+ thueVAT);
		System.out.println("tong so tien can tra: "+ (tien+thueVAT));
		System.out.println("muc tieu thu: "+ mucTieuThu(sodien));

		sc.close();
	}
}