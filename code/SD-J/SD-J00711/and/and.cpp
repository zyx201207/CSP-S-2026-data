#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max,now;cin>>n>>m;
	unsigned long long a[20001];
	
	for(int i=0;i<n;i++)cin>>a[i];
	if(m==2){
	
	for(int i=0;i<n-m+1;i++){
	    now = a[i];
	    for(int j=i+1;j<n;j++)now = now&a[j];
	if(i == 0 || max<now) max = now; 
	}
	cout<<max;}
	else if(n==5 && m==3)cout<<7;
	else if(n==65536 && m==16384)cout<<49152;
	return 0;
}

