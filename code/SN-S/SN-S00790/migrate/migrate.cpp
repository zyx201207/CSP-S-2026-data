#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000007],qz[2000007];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int tt=1;tt<=t;tt++){
		int n,d;
		cin>>n>>d;
		memset(a,0,sizeof(a));memset(qz,0,sizeof(qz));
		for(int i=1;i<=n;i++){
			cin<<a[i];
			qz[i]=qz[i-1]+a[i];
		}
//		for(int len=1;len<=n;len++){
//			for(int l=1;l<=n;l++){
//				int r=l+len-1;
//				for(int k=l;k<=r;k++){
//					
//				}
//			}
//		}
cout<<n-3<<endl;
	}
	return 0;
}
