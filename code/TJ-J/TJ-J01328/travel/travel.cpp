#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	string c1,s1,c2,s2;
//	int abc[18];
//	int abc["01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18"]
////	int abc['01','02','03','04','05','06','07','08','09','10','11','12','13','14','15','16','17','18'];
//
	int ana=0;
	cin>>c1>>s1>>c2>>s2;
//	
//
//
//	if(c1==c2){
//		cout<<1000<<s1+"A";
//		for(int i=0;i<18;i++){
//			ana=1000;
//			if(s1==abc[i]+"A"||abc[i]+"B"||abc[i]+"C"||abc[i]+"D"||abc[i]+"F" && s2==abc[i]+"A"||abc[i]+"B"||abc[i]+"C"||abc[i]+"D"||abc[i]+"F"){
//				ana=1100;
//				if(s1==abc[i]+"A"||abc[i]+"B"||abc[i]+"C" && s2==abc[i]+"A"||abc[i]+"B"||abc[i]+"C"){
//					ana=1110;
//					if(s1==abc[i]+"A"||abc[i]+"B" && s2==abc[i]+"A"||abc[i]+"B"){
//						ana=1111;
//					}
//					if(s1==abc[i]+"B"||abc[i]+"C" && s2==abc[i]+"B"||abc[i]+"C"){
//						ana=1111;
//					}
//				}
//				else if(s1==abc[i]+"D"||abc[i]+"F" && s2==abc[i]+"D"||abc[i]+"F"){
//					ana=1111;
//					
//				}
//			
//			}
//		}
//	}
//	else{
//		ana=0000;
//	}
//	cout<<ana;
	if(c1==c2){
		cout<<1111;
	}
	else{
		cout<<1110;
	}

	fclose(stdout);
	return 0;
}
