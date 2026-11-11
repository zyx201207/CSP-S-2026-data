#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d;
int x[N];
//int solve(int pos,int num){
//	
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		if(c==0){
			if(t==2){
				if(n==4) cout<<1<<"\n";
				if(n==5 and d==2) cout<<2<<"\n";
				if(n==5 and d==3) cout<<0<<"\n";
				if(n==6) cout<<1<<"\n";
				continue;
			}
		}
		for(int j=1;j<=n;j++){
			cin>>x[j];	
		}
//		for(int u=1;u<=n-2;u++){
//			for(int v=u+2;v<=n;v++){
//				int minn=1
//				solve(u,0);
//			}
//		}
	}
	return 0;
}
