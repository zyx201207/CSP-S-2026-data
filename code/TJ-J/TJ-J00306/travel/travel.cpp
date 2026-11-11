#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	int sum=0,flag=0,f2=0;
	for(int i=1;i<=17;i++){
		if(a1[i]!=a2[i]){
			flag=1;
		}
	}
	if(flag==1){
		cout<<0000;
		return 0;
	}else{
		sum+=1000;
	}
	for(int i=0;i<=1;i++){
		if(b1[i]!=b2[i]){
			f2=1;
		}
	}

	if(f2==1){
		cout<<1000;
		return 0;
	}else{
		sum+=100;
	}
	if(b1[2]<='c' && b2[2]<='c' || b1[2]>='d' && b1[2]<='f' && b2[2]>='d' && b2[2]<='f'){
		sum+=10;
	}else{
		cout<<1100;
		return 0;
	}
	if(b1[2]==b2[2]+1 || b1[2]==b2[2]-1){
		sum+=1;
		
	}else{
		cout<<1110;
		return 0;
	}
	cout<<sum;
	return 0;
}
