#include<bits/stdc++.h>
using namespace std;

string vietThuong(string s){
	for (char &c : s){
		c = tolower(c);
	}
	return s;
}


class Vehicle{
	private:
		int vehicleID;
		string vehicleType;
		int entryTime;
		int parkingDuration;
		double parkingFee;
		bool isOccupied;
	
	public:
		Vehicle(int vehicleID, string vehicleType, int entryTime, int parkingDuration, double parkingFee, bool isOccupied){
			this->vehicleID = vehicleID;
			this->vehicleType = vehicleType;
			this->entryTime = entryTime;
			this->parkingDuration = parkingDuration;
			this->parkingFee = parkingFee;
			this->isOccupied = isOccupied;
			
			calculateFee();
		}
		
		Vehicle(){
			vehicleID = 0;
			vehicleType = "";
			entryTime = 0;
			parkingDuration = 1;
			parkingFee = 0.0;
			isOccupied = false;
			
			calculateFee();
		}
		
		void setVehicleID(int id){
			this->vehicleID = id;
		}
		void setVehicleType(string t){
			this->vehicleType = t;
		}
		void setEntryTime(int entry){
			this->entryTime = entry;
		}
		void setParkingDuration(int pd){
			this->parkingDuration = pd;
		}
		void setParkingFee(double pf){
			this->parkingFee = pf;
		}
		void setOccupied(bool o){
			this->isOccupied = o;
		}
		
		int getVehicleID(){
			return this->vehicleID;
		}
		string getType(){
			return this->vehicleType;
		}
		int getEntryTime(){
			return this->entryTime;
		}
		int getParkingDuration(){
			return this->parkingDuration;
		}
		double getParkingFee(){
			return this->parkingFee;
		}
		bool getIsOccupied(){
			return this->isOccupied;
		}
		
		
		void display(){
			cout << "Ma so xe: " << vehicleID << endl
				 << "Loai xe: " << vehicleType << endl
				 << "Thoi gian vao: " << entryTime << endl
				 << "Thoi gian do: " << parkingDuration << endl
				 << "Phi do xe: " << parkingFee << "VND" << endl
				 << "Trang thai: " << isOccupied << endl;
		}
		
		void calculateFee(){
			string loaiXe = vehicleType;
			for(char &c : loaiXe){
				c = tolower(c);
			}
			if(isOccupied && ( (entryTime >= 6 && entryTime <= 9) || (entryTime >= 15 && entryTime <= 18) ) ){
				
				if(parkingDuration <= 2){
					
					if(vietThuong(vehicleType) == "car"){
						parkingFee = 6 * 1.3 * 25000 * parkingDuration;
					}
					
					else if(vietThuong(vehicleType) == "motorcycle"){
						parkingFee = 4 * 1.3 * 25000 * parkingDuration;
					}
					
					else if(vietThuong(vehicleType) == "bicycle"){
						parkingFee = 2 * 1.3 * 25000 * parkingDuration;
					}
				}
				
				else{
					
					if(vietThuong(vehicleType) == "car"){
						parkingFee = ( 6 * 1.3 * 25000 * 2) + ( 6 * 0.9 * 25000 * (parkingDuration-2));
					}
					
					else if(vietThuong(vehicleType) == "motorcycle"){
						parkingFee = ( 4 * 1.3 * 25000 * 2) + ( 4 * 0.9 * 25000 * (parkingDuration-2));
					}
					
					else if(vietThuong(vehicleType) == "bicycle"){
						parkingFee = ( 2 * 1.3 * 25000 * 2) + ( 2 * 0.9 * 25000 * (parkingDuration-2));
					}
				}
			}
			
			else if( isOccupied ){
				
				if(parkingDuration <= 2){
					
					if(vietThuong(vehicleType) == "car"){
						parkingFee = 6 * 0.95 * 25000 * parkingDuration;
					}
					
					else if(vietThuong(vehicleType) == "motorcycle"){
						parkingFee = 4 * 0.95 * 25000 * parkingDuration;
					}
					
					else if(vietThuong(vehicleType) == "bicycle"){
						parkingFee = 2 * 0.95 * 25000 * parkingDuration;
					}
				}
				
				else{
					
					if(vietThuong(vehicleType) == "car"){
						parkingFee = ( 6 * 0.95 * 25000 * 2) + ( 6 * 0.9 * 25000 * (parkingDuration-2) );
					}
					
					else if(vietThuong(vehicleType) == "motorcycle"){
						parkingFee = ( 4 * 0.95 * 25000 * 2) + ( 4 * 0.9 * 25000 * (parkingDuration-2) );
					}
					
					else if(vietThuong(vehicleType) == "bicycle"){
						parkingFee = ( 2 * 0.95 * 25000 * 2) + ( 2 * 0.9 * 25000 * (parkingDuration-2) );
					}
				}
				
			}
			else{
				parkingFee = 0.0;
			}
		}
};

class ParkingLot{
	private:
		int parkID;
		char size;
		Vehicle vehicle1, vehicle2, vehicle3;
		bool hasVehicle1, hasVehicle2, hasVehicle3;
	public:
		ParkingLot(int parkID, char size){
			this->parkID = parkID;
			this->size = size;
			
			hasVehicle1 = false;
			hasVehicle2 = false;
			hasVehicle3 = false;
		}
		ParkingLot(){
			parkID = 0;
			size = '\0';
			hasVehicle1 = false;
			hasVehicle2 = false;
			hasVehicle3 = false;
		}
		
		int getParkID(){
			return this -> parkID;
		}
		
		Vehicle getVehicle1(){
			return this -> vehicle1;
		}
		
		Vehicle getVehicle2(){
			return this -> vehicle2;
		}
		
		Vehicle getVehicle3(){
			return this -> vehicle3;
		}
		
		bool getHasVehicle1(){
			return this -> hasVehicle1;
		}
		
		bool getHasVehicle2(){
			return this -> hasVehicle2;
		}
		
		bool getHasVehicle3(){
			return this -> hasVehicle3;
		}
		
		bool addVehicle(const Vehicle& v){
			if(size == 's' || size == 'S'){
				if(!hasVehicle1){
					vehicle1 = v;
					hasVehicle1 = true;
					return true;
				}
				return false;
			}
			else if(size == 'm' || size == 'M'){
				if(!hasVehicle1){
					vehicle1 = v;
					hasVehicle1 = true;
					return true;
				}
				else if(!hasVehicle2){
					vehicle2 = v;
					hasVehicle2 = true;
					return true;
				}
				return false;
			}
			else{
				if(!hasVehicle1){
					vehicle1 = v;
					hasVehicle1 = true;
					return true;
				}
				else if(!hasVehicle2){
					vehicle2 = v;
					hasVehicle2 = true;
					return true;
				}
				else if(!hasVehicle3){
					vehicle3 = v;
					hasVehicle3 = true;
					return true;
				}
				return false;
			}
		}
		bool removeVehicle(int vID){
			if(hasVehicle1 && vehicle1.getVehicleID() == vID){
				hasVehicle1 = false;
				return true;
			}
			if(hasVehicle2 && vehicle2.getVehicleID() == vID){
				hasVehicle2 = false;
				return true;
			}
			if(hasVehicle3 && vehicle3.getVehicleID() == vID){
				hasVehicle3 = false;
				return true;
			}
			return false;
			
		}
		void displayLotInfor(){
			cout << "Ma bai do: " << parkID << endl
				 << "Kich thuoc: " << size << endl;
			
			cout << "\nDanh sach xe trong bai:\n";
			if(hasVehicle1){
				vehicle1.display();
				cout << "\n";
			}
			
			if(hasVehicle2){
				vehicle2.display();
				cout << "\n";
			}
			
			if(hasVehicle3){
				vehicle3.display();
				cout << "\n";
			}
			
		}
};

class SystemInterface{
	private:
		ParkingLot parkingLot1, parkingLot2, parkingLot3;
		bool hasLot1, hasLot2, hasLot3;
		
		
	public:
		SystemInterface(){
			hasLot1 = false;
			hasLot2 = false;
			hasLot3 = false;
		}
		void runMenu(){
			int luaChon;
			int cnt1 = 0;
			do{
				cout << "-------------------MENUUUUUU-------------------\n"
					 << "1. Tao bai do xe moi.\n"
					 << "2. Them xe vao bai do.\n"
					 << "3. Xoa 1 bai do xe.\n"
					 << "4. Lay xe ra khoi bai do.\n"
					 << "5. Hien thi danh sach tat ca cac bai do xe.\n"
					 << "6. Hien thi danh sach xe theo bai cu the.\n"
					 << "7. Liet ke xe theo loai phuong tien.\n"
					 << "8. Xem bao cao tom tat phi do xe trung binh.\n"
					 << "9. Thoat chuong trinh.\n"
					 << "-----------------------------------------------\n"
					 << "Nhap lua chon cua ban (1-9): ";
				cin >> luaChon;
				switch(luaChon){
					
					case 1:{
						cout << "-------------Dang tao bai do xe moi------------\n";
						if(hasLot1 && hasLot2 && hasLot3){
							cout << "Da vuot qua so luong bai do xe\n";
							break;
						}
						int parkID;
						char size;
						cout << "Hay nhap parkID: "; cin >> parkID;
						cout << "Hay nhap kich thuoc: "; cin >> size;
						bool ktra = false;
						if(hasLot1 && parkingLot1.getParkID() == parkID) ktra = true;
						if(hasLot2 && parkingLot2.getParkID() == parkID) ktra = true;
						if(hasLot3 && parkingLot3.getParkID() == parkID) ktra = true;
						
						if(ktra){
							cout << "ID cua bai do xe bi trung\n";
						}
						else{
							if(!hasLot1){
								parkingLot1 = ParkingLot(parkID, size);
								hasLot1 = true;
								cout << "Them bai do xe thanh cong\n";
							}
							else if(!hasLot2){
								parkingLot2 = ParkingLot(parkID, size);
								hasLot2 = true;
								cout << "Them bai do xe thanh cong\n";
							}
							else if(!hasLot3){
								parkingLot3 = ParkingLot(parkID, size);
								hasLot3 = true;
								cout << "Them bai do xe thanh cong\n";
							}
						}
						break;
					}
					
					
					case 2:{
						int vehicleID;
						string vehicleType;
						int entryTime;
						int parkingDuration;
						bool isOccupied = true;
						double parkingFee;
						cout << "---------------Dang them xe vao bai do---------------\n";
						cout << "Nhap ID xe: "; cin >> vehicleID;
						cout << "Nhap loai xe: "; cin >> vehicleType;
						cout << "Nhap thoi gian vao: "; cin >> entryTime;
						cout << "Nhp thoi gian do: "; cin >> parkingDuration;
						Vehicle v(vehicleID, vehicleType, entryTime, parkingDuration, 0.0, true);
						bool ktra = false;
						if(hasLot1 && parkingLot1.addVehicle(v)){
							ktra = true;
						}else if(hasLot2 && parkingLot2.addVehicle(v)){
							ktra = true;
						}else if(hasLot3 && parkingLot3.addVehicle(v)){
							ktra = true;
						}
						
						if(ktra){
							cout << "Them xe thanh cong\n";
						}
						else{
							cout << "Them xe that bai\n";
						}
						
						break;
					}
					
					
					case 3:{
						int parkID;
						cout << "----------------Dang xoa bai do xe----------------\n";
						cout << "Nhap ID bai do xe can xoa: "; cin >> parkID;
						bool ktra = false;
						if(hasLot1 && parkingLot1.getParkID() == parkID){
							hasLot1 = false;
							ktra = true;
						}else if(hasLot2 && parkingLot2.getParkID() == parkID){
							hasLot2 = false;
							ktra = true;
						}else if(hasLot3 && parkingLot3.getParkID() == parkID){
							hasLot3 = false;
							ktra = true;
						}
						
						if(ktra){
							cout << "Xoa bai do xe thanh cong\n";
						}
						else{
							cout << "Khong tim thay bai do xe\n";
						}
						break;
					}
					
					case 4:{
						int vehicleID;
						cout << "---------------Dang lay xe ra khoi bai---------------\n";
						cout << "Nhap ID xe can lay: "; cin >> vehicleID;
						bool ktra = false;
						if(hasLot1 && parkingLot1.removeVehicle(vehicleID)){
							ktra = true;
						}
						if(hasLot2 && parkingLot2.removeVehicle(vehicleID)){
							ktra = true;
						}
						if(hasLot3 && parkingLot3.removeVehicle(vehicleID)){
							ktra = true;
						}
						
						if(ktra){
							cout << "Lay xe ra khoi bai thanh cong\n";
						}
						else{
							cout << "Khong tim thay xe\n";
						}
						break;
					}
					
					case 5:{
						cout << "--------Hien thi danh sach cac bai do xe hien co--------\n";
						if(!hasLot1 && !hasLot2 && !hasLot3){
							cout << "He thong chua co bai do xe nao\n";
						}
						else{
							if(hasLot1){
								parkingLot1.displayLotInfor();
								cout<<"\n";
							}
							if(hasLot2){
								parkingLot2.displayLotInfor();
								cout<<"\n";
							}
							if(hasLot3){
								parkingLot3.displayLotInfor();
								cout<<"\n";
							}
						}
						break;
					}
					
					case 6:{
						int parkID;
						cout << "---------Thong tin cua bai do xe---------\n";
						
						if(!hasLot1 && !hasLot2 && !hasLot3){
							cout << "He thong chua co bai do xe nao\n";
						}
						else{
							cout << "Nhap ID bai do xe: "; cin >> parkID;
							bool ktra = false;
							if(hasLot1 && parkingLot1.getParkID() == parkID){
								parkingLot1.displayLotInfor();
								ktra = true;
							}
							else if(hasLot2 && parkingLot2.getParkID() == parkID){
								parkingLot2.displayLotInfor();
								ktra = true;
							}
							else if(hasLot3 && parkingLot3.getParkID() == parkID){
								parkingLot3.displayLotInfor();
								ktra = true;
							}
							
							if(!ktra){
								cout << "Khong tim thay bai do xe\n";
							}
						}
						break;
					}
					
					case 7:{
						string typeVehicle;
						cout << "--------------Dang tim kiem xe tuong ung--------------";
						cout << "Nhap loai xe can tim: "; cin >> typeVehicle;
						string loaiXe = vietThuong(typeVehicle);
						bool ktra = false;
						if(hasLot1){
							if(parkingLot1.getHasVehicle1() && vietThuong(parkingLot1.getVehicle1().getType()) == loaiXe){
								cout << "xe do o bai: " << parkingLot1.getParkID() << "\n";
								parkingLot1.getVehicle1().display();
								cout << "\n";
								ktra = true;
							}
							if(parkingLot1.getHasVehicle2() && vietThuong(parkingLot1.getVehicle2().getType()) == loaiXe){
								cout << "xe do o bai: " << parkingLot1.getParkID() << "\n";
								parkingLot1.getVehicle2().display();
								cout << "\n";
								ktra = true;
							}
							if(parkingLot1.getHasVehicle3() && vietThuong(parkingLot1.getVehicle3().getType()) == loaiXe){
								cout << "xe do o bai: " << parkingLot1.getParkID() << "\n";
								parkingLot1.getVehicle3().display();
								cout << "\n";
								ktra = true;
							}
						}
						if(hasLot2){
							if(parkingLot2.getHasVehicle1() && vietThuong(parkingLot2.getVehicle1().getType()) == loaiXe){
								cout << "Xe dang do o bai: " << parkingLot2.getParkID() << "\n";
								parkingLot2.getVehicle1().display();
								cout << "\n";
								ktra = true;
							}
							if(parkingLot2.getHasVehicle2() && vietThuong(parkingLot2.getVehicle2().getType()) == loaiXe){
								cout << "xe do o bai: " << parkingLot2.getParkID() << "\n";
								parkingLot2.getVehicle2().display();
								cout << "\n";
								ktra = true;
							}
							if(parkingLot2.getHasVehicle3() && vietThuong(parkingLot2.getVehicle3().getType()) == loaiXe){
								cout << "xe do o bai: " << parkingLot2.getParkID() << "\n";
								parkingLot2.getVehicle3().display();
								cout << "\n";
								ktra = true;
							}
						}
						if(hasLot3){
							if(parkingLot3.getHasVehicle1() && vietThuong(parkingLot3.getVehicle1().getType()) == loaiXe){
								cout << "Xe dang do o bai: " << parkingLot3.getParkID() << "\n";
								parkingLot3.getVehicle1().display();
								cout << "\n";
								ktra = true;
							}
							if(parkingLot3.getHasVehicle2() && vietThuong(parkingLot3.getVehicle2().getType()) == loaiXe){
								cout << "xe do o bai: " << parkingLot3.getParkID() << "\n";
								parkingLot3.getVehicle2().display();
								cout << "\n";
								ktra = true;
							}
							if(parkingLot3.getHasVehicle3() && vietThuong(parkingLot3.getVehicle3().getType()) == loaiXe){
								cout << "xe do o bai: " << parkingLot3.getParkID() << "\n";
								parkingLot3.getVehicle3().display();
								cout << "\n";
								ktra = true;
							}
						}
						
						if(!ktra){
							cout << "Ko tim thay xe hop le!!!";
						}
						break;
					}
					
					case 8:{
						
						break;
					}
					
				}		
			}while(luaChon != 9);
		}
};
int main(){
	SystemInterface si;
	si.runMenu();
	return 0;
}
