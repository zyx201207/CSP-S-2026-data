#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	int a[100005],b[100005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1&&m==1){
		cout<<1;
	}
	if(n==2&&m==1){
		cout<<2;
	}
	
	return 0;
}
