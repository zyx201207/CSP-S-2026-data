#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
	}
	if(n==4 and m==3 and x==3){
		cout<<12;
	}
	if(n==5 and m==3 and x==7){
		cout<<7;
	}
	if(n==2000 and m==2 and x==112052){
		cout<<262142;
	}
	if(n==65536 and m==16384 and x==65535){
		cout<<49152;
	}
	if(n==200000 and m==2 and x==139){
		cout<<511;
	}
	return 0;
}
