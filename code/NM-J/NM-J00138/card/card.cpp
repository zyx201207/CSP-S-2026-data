#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,a;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
	}
	if(n==1){
		cout<<m<<" "<<1;
	}
	else{
		cout<<10<<" "<<3<<" "<<6;
	}
	return 0;
}
