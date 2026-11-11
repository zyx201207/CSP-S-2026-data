#include<bits/stdc++.h>
using namespace std;
int c,q;
long long n;
long long d;
long long x[2000001];
long long f[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--){
		cin>>n>>d;
		long long ans=0;
		for(long long i=1;i<=n;i++)cin>>x[i];
		memset(f,0,sizeof(f));
		long long j=1;
		for(long long i=1;i<=n;i++){
			while(j<=n&&x[j]-x[i]<=d)j++;
			f[i]=j-1;
		}
		for(long long i=1;i<=n;i++){
			long long t=i,p1=1,p2=1;
			while(p1<=2){
				if(f[t]<=t)break;
				if(p1==1){
					if(p2==1){
						if(f[t]-2>t){
							ans+=f[f[t]-1]-f[f[t]-2];
						}else if(f[t]-1>t){
							ans+=f[f[t]-1]-f[t];
						}
					}
				}else{
					if(f[t]-1>t){
						ans+=f[f[t]]-f[f[t]-1];
					}else{
						ans+=f[f[t]]-f[t];
					}
				}
				int t1=p1,t2=p2;
				if(f[f[t]]>f[t]){
					if(f[f[t]-2]>=f[f[t]])p1=3;
					else if(f[f[t]-1]>=f[f[t]])p1=t1+t2;
					else p1=t1;
				}
				if(f[f[t]]-1>f[t]){
					if(f[f[t]-1]>=f[f[t]]-1)p2=2;
					else p2=t1;
				}
				t=f[t];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

