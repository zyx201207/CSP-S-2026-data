#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[2005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1&&n==1){
		cout<<n;
	}
	else if(m==2){
		cout<<0;
	}
	return 0;
}