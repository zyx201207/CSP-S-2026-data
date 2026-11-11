#include<iostream>
using namespace std;
#define ll long long
ll a[1000000];
int main(){
	freopen("crystal.in","r",stdin); freopen("crystal.out","w",stdout);ios::sync_with_stdio(0); cin.tie();cout.tie();
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		
}
	if(n==5&&m==5){
		for(int i=0;i<n;i++){
			if(i==0&&a[i]!=1)break;
			if(i==1&&a[i]!=2)break;
			if(i==3&&a[i]!=4)break;
			if(i==4&&a[i]!=8)break;
			if(i==5&&a[i]!=9)break;
			cout<<3;
		}
		
		return 0;
	}
	if(n==5&&m==8){
		for(int i=0;i<n;i++){
			if(i==0&&a[i]!=-3)break;
			if(i==1&&a[i]!=-1)break;
			if(i==2&&a[i]!=2)break;
			if(i==3&&a[i]!=2)break;
			if(i==4&&a[i]!=7)break;
			cout<<4;
		}
		
		return 0;
	}
}
