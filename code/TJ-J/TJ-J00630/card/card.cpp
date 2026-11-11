#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int x=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]&&i>1){
			cout<<x;
			x=1;
		}
		else x++;
	}
	return 0;
} 
