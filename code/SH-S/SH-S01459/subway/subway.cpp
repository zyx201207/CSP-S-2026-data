#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;

	if(c==21||c==20||n<=2){
		long long sb1[500005],sb2[500005],w[500005],tf=INT_MAX;
		for(int i=1;i<=m;i++)cin>>w[i];
		if(n==1){
			cin>>k;
			while(k--){
				int a,t;
				cin>>a>>t;
				sb1[a]=t;
			}
			while(q--){
				int x,y;
				cin>>x>>y;
				cout<<w[x]+w[y]+sb1[x]+sb1[y];
			}
		}
		else
		{
			cin>>k;
			while(k--){
				int a,t;
				cin>>a>>t;
				sb1[a]=t;
			}
			cin>>k;
			while(k--){
				int a,t;
				cin>>a>>t;
				sb2[a]=t;
				if(sb1[a]&&sb1[a]+sb2[a]<tf)tf=sb1[a]+sb2[a];
			}
			while(q--){
				int x,y;
				cin>>x>>y;
				if(!sb1[x])sb1[x]=INT_MAX;
				if(!sb2[x])sb2[x]=INT_MAX;
				if(!sb1[y])sb1[y]=INT_MAX;
				if(!sb2[y])sb2[y]=INT_MAX;
				cout<<w[x]+w[y]+min(min(sb1[x]+sb1[y],sb2[x]+sb2[y]),min(sb1[x]+sb2[y]+tf,sb2[x]+sb1[y]+tf))<<endl;
			}
		}
	}
}
