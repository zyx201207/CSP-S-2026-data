#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500001];
void f1(){
	long long s=0,c=0;
	while(c<n&&s<=m){
		c++;
		s+=c;
	} 
	cout<<c;
	return;
}
void f2(){
	long long cha=a[2]-a[1],c=0,s=0;
	while(c<n&&s<=m){
		c+=cha;
		s+=c;
	} 
	cout<<c/cha;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int bj1=0,bj2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			bj1=1;
		}
		if(i!=1){
			if(a[i]-a[i-1]!=a[2]-a[1]){
				bj2=1;
			}
		}
	}
	if(bj1==0){
		f1(); 
		return 0; 
	}
	if(bj2==0){
		f2();
		return 0;
	}
	return 0;
}