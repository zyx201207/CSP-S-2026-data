#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	char a[1001],b[1001];
	cin>>x;
	int sum,cnt;
	for(int i=1;i<=3;i++){
		cin>>a[i];
	}
	if(a[3]=='A'){
		sum=1;
	}
	if(a[3]=='B'){
		sum=2;
	}
	if(a[3]=='C'){
		sum=3;
	}
	if(a[3]=='D'){
		sum=-4;
	}
	if(a[3]=='F'){
		sum=-5;
	}
	cin>>y;
	for(int i=1;i<=3;i++){
		cin>>b[i];
	}
	if(b[3]=='A'){
		cnt=1;
	}
	if(b[3]=='B'){
		cnt=2;
	}
	if(b[3]=='C'){
		cnt=3;
	}
	if(b[3]=='D'){
		cnt=-4;
	}
	if(b[3]=='F'){
		cnt=-5;
	}
	if(x==y){
		cout<<1;
		bool ans=1;
		for(int i=1;i<=2;i++){
			if(a[i]!=b[i]){
				ans=0;
				break;
			}
		}
		if(ans==1){
			cout<<1;
		}else{
			cout<<0;
		}
		if(a[3]>='A'&&a[3]<='C'&&b[3]>='A'&&b[3]<='C'||a[3]>='D'&&a[3]<='F'&&b[3]>='D'&&b[3]<='F'){
			cout<<1;
		}else{
			cout<<0;
		} 
		if(sum-cnt==1||sum-cnt==-1){
			cout<<1;
		}else{ 
			cout<<0;
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
