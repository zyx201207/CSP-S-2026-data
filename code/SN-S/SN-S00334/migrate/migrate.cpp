//西安铁一中滨河高级中学 耿禹墨 SN-S00334
#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[2000006],d[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[i];
			if(i!=1){
				d[i]=x[i]-x[i-1];
			}
		}
	}
	for(int i=1;i<=n;i++){
		d[i+1]+=d[i];
	}
	cout<<d[n]-d;
	return 0;
}
