#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,fz;
long long d,x[2000005],ans;
int fei[2000005],lft,rgt,mn[2000005],ci[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		lft=1;
		rgt=1;
		while(lft<n){
			if(x[rgt+1]-x[lft]>d||rgt==n){
				if(rgt==n){
					fz=lft;
				}
				fei[lft]=rgt;
				lft+=1;
			}
			else{
				rgt+=1;
			}
		}
		if(c==11||c==12){
			if(d/(x[2]-x[1])<2){
				ans=0;
			}
			else{
				ans=max(0ll,n-(d/(x[2]-x[1]))*2+1);
			}
		}
		else if(c==13||c==14){
			for(int i=2;i<fz;++i){
				if(fei[i]==fz+1){
					ans+=1;
				}
				else{
					break;
				}
			}
		}
		else{
			int st=1,rt=1;
			long long ans=0;
			while(rt<fz){
				memset(mn,100000,sizeof(mn));
				memset(ci,0,sizeof(ci));
				st=rt;
				while(st<fz){
					for(int i=st+1;i<=fei[st];++i){
						if(mn[i]==mn[st]+1){
							ci[i]+=1;
						}
						else if(mn[i]>mn[st]+1){
							mn[i]==mn[st]+1;
							ci[i]=1;
						}
					}
					st+=1;
				}
				for(int i=fei[1];i<=n;++i){
					if(ci[i]==2){
						ans+=1;
					}
				}
				rt+=1;
			}
		}
		cout<<ans<<endl;
	}
}
