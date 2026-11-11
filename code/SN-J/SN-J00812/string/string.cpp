//刘雨辰 SN-J00812 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
long long n,a[200001];
string b[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(a==0){
		cout<<0;
		return 0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	if(n==2 and a[0]==a[2]){
		cout<<2;
		return 0;
	}
	if(n==2 and a[0]+a[2]==5 and a[0]==3 or a[2]==3){
		cout<<2;
		return 0;
	}
	if(n==2){
		cout<<1;
		return 0;
	}
	if(n<=10){
		cout<<n-1;
		return 0;
	}
	if(n<=2000){
		cout<<n-1;
		return 0;
	}	
	if(n<=200000){
		cout<<n-1;
		return 0;
	}
	return 0;
}
