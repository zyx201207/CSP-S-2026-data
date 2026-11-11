#include<bits/stdc++.h>
using namespace std;
string c1,c2,Seat_1,Seat_2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>Seat_1>>c2>>Seat_2;
	if(c1==c2){
		printf("%d",1);
		if(Seat_1[0]+Seat_1[1]==Seat_2[0]+Seat_2[1]){
			printf("%d",1);
			bool l_1=(Seat_1[2]<='C');
			bool l_2=(Seat_2[2]<='C');
			if(l_1&&l_2){
				printf("%d",1);
				if((Seat_2[2]-Seat_1[2]==1)||(Seat_2[2]-Seat_1[2]==-1))
					printf("%d",1);
				else
					printf("%d",0);
			}else if(!l_1&&!l_2){
				printf("11");
			}else{
				printf("00");
			}
		}else{
			printf("000");
		}
	}else{
		printf("0000");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
