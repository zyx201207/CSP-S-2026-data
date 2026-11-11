#include<bits/stdc++.h>
using namespace std;
string name1,name2,seat1,seat2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>name1>>seat1>>name2>>seat2;
	if(name1.size()!=name2.size()){
		cout<<"0000";
		return 0;
	}
	else{
		int long_=name1.size();
		for(int i=0;i<long_;i++){
			if(name1[i]!=name2[i]){
				cout<<"0000";
				return 0;
			}
		}
		cout<<1;
		int num1=0,num2=0;
		num1=(seat1[1]-'0')+10*(seat1[0]-'0');
		num2=(seat2[1]-'0')+10*(seat2[0]-'0');
		if(num1==num2){
			cout<<1;
		}
		else{
			cout<<"000";
			return 0;
		}
		int pan1=0,pan2=0,p1=0,p2=0;
		if(seat1[2]=='A' || seat1[2]=='B' || seat1[2]=='C') pan1=1;
		if(seat2[2]=='A' || seat2[2]=='B' || seat2[2]=='C') pan2=1;
		if(pan1!=pan2){
			cout<<"00";
			return 0;
		}
		else cout<<1;
		p1=(int) seat1[2];
		p2=(int) seat2[2];
		if(abs(p1-p2)==1 || (p1==68 && p2==70)){
			cout<<1;
		}
		else{
		cout<<"0";
			return 0;
		}
	}
	return 0;
}
