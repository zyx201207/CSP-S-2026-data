#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll c,n,m,d,q,sum,x,w,e;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>x;
		sum+=x;
	} 
	for(int i=1;i<=n;i++){
		cin>>w;
		for(int j=1;j<=w;j++){
			cin>>e>>x;
			sum+=x;
		}
	}
	for(int i=1;i<=q;i++){
		cout<<sum<<"\n";
	}
	return 0;
}
