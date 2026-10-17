#include<bits/stdc++.h>
using namespace std;
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
		}
		
		Vehicle(){
			vehicleID = 0;
			vehicleType = "";
			entryTime = 0;
			parkingDuration = 1;
			parkingFee = 0.0;
			isOccupied = false;
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
			if(isOccupied && ( (entryTime >= 6 && entryTime <= 9) || (entryTime >= 15 && entryTime <= 18) ) ){
				
				if(parkingDuration <= 2){
					
					if(vehicleType == "car"){
						parkingFee = 6 * 1.3 * 25000 * parkingDuration;
					}
					
					else if(vehicleType == "motorcycle"){
						parkingFee = 4 * 1.3 * 25000 * parkingDuration;
					}
					
					else if(vehicleType == "bicycle"){
						parkingFee = 2 * 1.3 * 25000 * parkingDuration;
					}
				}
				
				else{
					
					if(vehicleType == "car"){
						parkingFee = ( 6 * 1.3 * 25000 * 2) + ( 6 * 0.9 * 25000 * (parkingDuration-2));
					}
					
					else if(vehicleType == "motorcycle"){
						parkingFee = ( 4 * 1.3 * 25000 * 2) + ( 4 * 0.9 * 25000 * (parkingDuration-2));
					}
					
					else if(vehicleType == "bicycle"){
						parkingFee = ( 2 * 1.3 * 25000 * 2) + ( 2 * 0.9 * 25000 * (parkingDuration-2));
					}
				}
			}
			
			else if( isOccupied ){
				
				if(parkingDuration <= 2){
					
					if(vehicleType == "car"){
						parkingFee = 6 * 0.95 * 25000 * parkingDuration;
					}
					
					else if(vehicleType == "motorcycle"){
						parkingFee = 4 * 0.95 * 25000 * parkingDuration;
					}
					
					else if(vehicleType == "bicycle"){
						parkingFee = 2 * 0.95 * 25000 * parkingDuration;
					}
				}
				
				else{
					
					if(vehicleType == "car"){
						parkingFee = ( 6 * 0.95 * 25000 * 2) + ( 6 * 0.9 * 25000 * (parkingDuration-2) );
					}
					
					else if(vehicleType == "motorcycle"){
						parkingFee = ( 4 * 0.95 * 25000 * 2) + ( 4 * 0.9 * 25000 * (parkingDuration-2) );
					}
					
					else if(vehicleType == "bicycle"){
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
			
			cout << "Danh sach xe trong bai:\n";
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
};
int main(){
	
}