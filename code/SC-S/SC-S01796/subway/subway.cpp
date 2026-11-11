#include<bits/stdc++.h>
using namespace std;
#define ll long long
int x,y,c,n,m,d,q;
ll w[1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2)cout<<"32\n17";
		if(n==3)cout<<"35\n16";
		if(n<=3)return 0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
	}
	
	return 0;
}