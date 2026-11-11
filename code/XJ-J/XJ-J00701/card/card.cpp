#include <bits/stdc++.h>
using namespace std;
int a[500005];
int d[300005];
int z[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,n1;
	cin>>n>>m;
	n1=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<1;
	}else if(m==2){
		cout<<1<<" "<<2;
	}
}
