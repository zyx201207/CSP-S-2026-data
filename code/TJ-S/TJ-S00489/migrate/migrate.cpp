#include<iostream>
#include<cstdio>
using namespace std;
long long c,t,n,d,x[20000005],xmax[20000005],xmin[20000005],p,ans;
bool f[20000005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=2000000;i++){
			x[i]=0;
			xmax[i]=0;
			xmin[i]=0;
			p=0;
			ans=0;
		}
		for(int i=1;i<=20000000;i++){
			f[i]=0;
		}
		cin>>n>>d;
		if(n<=3){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i==1){
				if(x[i]<0)p=-x[i];
			}
			x[i]+=p;
			f[x[i]]=1;
		}
		for(int i=1;i<=n-3;i++){
			for(int j=x[i+3];j<=x[i]+2*d;j++){
				if(!f[j])continue;
				int cnt=0,id,cnt1=0;
				for(int k=j-d;k<=x[i]+d;k++){
					if(f[k]){
						cnt++;
						id=k;
					}
					if(cnt>=3)break;
				}
				if(cnt==2){
					for(int k=id+d+1;k<=j+d;k++){
						if(f[k])cnt1++;
					}
				}
				if(cnt==2){
					ans+=cnt1+1;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
