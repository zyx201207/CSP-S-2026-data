#include<bits/stdc++.h>
using namespace std;
string cx1,cx2;
string zw1,zw2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>zw1>>cx2>>zw2;
	if(cx1==cx2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(zw1[0]==zw1[0]&&zw1[1]==zw2[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	} 
	char c1=zw1[2],c2=zw2[2];
	char cc[3]={'A','B','C'};
	if(int(c1)+int(c2)==138){
		cout<<11;
	}
	else{
		bool f1=0,f2=0; 
		for(int i=0;i<3;i++){
			if(c1==cc[i])f1=1;
			if(c2==cc[i])f2=1;
		}
		if(f1&&f2)cout<<1;
		else cout<<0;
		if(int(c1)+int(c2)==131||int(c1)+int(c2)==133){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
