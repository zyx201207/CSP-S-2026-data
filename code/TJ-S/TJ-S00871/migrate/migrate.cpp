#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
bool b[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		for(int t1=1;t1<=t;t1++){
			int n,k;
			cin>>n>>k;
			for(int i=1;i<=n;i++) cin>>a[i];
			int tem=a[2]-a[1],tmp=k/tem,sum=0;
//			if(tmp){
//				if(tmp%2==0){
//					if(2*tmp-1<=n-1) cout<<-3*tmp*(3*tmp-1)/2+n*(3*tmp-1)/2<<endl;
//					else{
//						if(n%2==0){
//							cout<<n*(n-3-tmp)/2-(n+tmp-2)*(n-3-tmp)/2<<endl;
//						}else{
//							cout<<n*(n-2-tmp)/2-(n+tmp-1)*(n-2-tmp)/2<<endl;
//						}
//					}
//				}else{
//					if(2*tmp-1<=n-1) cout<<n*(tmp-2)-(tmp-2)*(3*tmp+1)/2<<endl;
//					else{
//						if(n%2==0){
//							cout<<n*(n-4-tmp)/2-(n+tmp-1)*(n-4-tmp)/2<<endl;
//						}else{
//							cout<<n*(n-3-tmp)/2-(n+tmp)*(n-3-tmp)/2<<endl;
//						}
//					}
//				}
//			}else cout<<0<<endl;
			for(int i=1;i<=tmp-1;i++) b[i*2]=1;
			for(int i=tmp+1;i<=2*tmp-1&&i<=n-1;i++){
				if(b[i]) continue;
				sum=sum+(n-i);
			}
			cout<<sum<<endl;
		}	
	}
	return 0;
}













































































//What are you looking for?
//Is it f.C?
