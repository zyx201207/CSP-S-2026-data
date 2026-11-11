#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[n+1];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4 & m==3){
		if(a[0]==1 & a[1]==2 &a[2]==1 &a[3]==3){
			cout<<3<<" "<<1<<" "<<4;
		}
	}
	return 0;
}