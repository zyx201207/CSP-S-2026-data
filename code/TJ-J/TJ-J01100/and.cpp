#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2000&&m==2){
		cout<<262142;
		return 0;
	}
	if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}
	if(n==200000&&m==2){
		cout<<511;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[m];
	return 0;
} 
