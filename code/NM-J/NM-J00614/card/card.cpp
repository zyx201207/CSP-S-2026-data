#include<bits/stdc++.h>
using namespace std;
struct c{
	int d;
	int z;
}a[500010];
int p=300010;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].d;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	return 0;
}
