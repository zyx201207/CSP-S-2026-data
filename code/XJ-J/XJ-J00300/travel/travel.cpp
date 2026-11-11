#include<bits/stdc++.h>
using namespace std;
char a[10] = {'A','B','C','D','F'};
int find(char position){
	for(int i = 0;i<5;i++){
		if(a[i]==position){
			return i;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int coach1 = 0;
	string seat1 = " ";
	int coach2 = 0;
	string seat2 = " ";
	cin>>coach1>>seat1>>coach2>>seat2;
	int a,b,c,d=0;
	if(coach1 == coach2){
		a = 1;
		if(seat1[0]==seat2[0]&&seat1[1]==seat2[1]){
			b=1;		
			if(find(seat1[2])<=2&&find(seat1[2])<=2||find(seat2[2])>2&&find(seat2[2])>2){
				c=1;
				if(find(seat1[2])-find(seat2[2])==1||find(seat1[2])-find(seat2[2])==-1){
					d=1;
				}
			}
		}
	}
	if(a ==1){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(b==1){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(c ==1){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(d ==1){
		cout<<'1';
	}else{
		cout<<'0';
	}

	
	
}