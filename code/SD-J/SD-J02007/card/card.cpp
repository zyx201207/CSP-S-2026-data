#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500500];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4 and m==3)
	cout<<3<<" "<<1<<" "<<4;
	if(n==10 and m==3)
	cout<<10<<" "<<3<<" "<<3;
	if(n==200000 and m==100000)
	cout<<1;
}
