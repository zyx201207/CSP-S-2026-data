#include<bits/stdc++.h>
using namespace std;
string c1,s1;
string c2,s2;
char ch1[5]={',','A','B','C',','};
char ch2[4]={',','D','F',','};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				cout<<"000";
				return 0;
			}
		}
		cout<<"1";
		bool flag=false;
		char ends1=s1[2],ends2=s2[2];
		if(ends1=='A'||ends1=='B'||ends1=='C'){
			if(ends2=='A'||ends2=='B'||ends2=='C'){
				flag=true;//tong yi ce
			}
		}
		if(ends1=='D'||ends1=='F'){
			if(ends1=='D'||ends1=='F'){
				flag=true;
			}
		}
		if(flag==false){
			cout<<"00";
			return 0;
		}
		cout<<"1";
		
		for(int i=1;i<=3;i++){
			if(ends1==ch1[i]){
				int left=i-1,right=i+1;
				if(ends2==ch1[left]||ends2==ch1[right]){
					cout<<1;
					return 0;
				}
			}
		}
		for(int i=1;i<=2;i++){
			if(ends1==ch2[i]){
				int left=i-1,right=i+1;
				if(ends2==ch2[left]||ends2==ch2[right]){
					cout<<1;
					return 0;
				}
			}
		}
		cout<<0;
	}
	return 0;
}
