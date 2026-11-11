#include<bits/stdc++.h>
#define int long long
using namespace std;
int ch,T,n,d,x[2001000],c[2001000];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>ch>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
			c[i]=x[i]-x[i-1];
		}
		if(ch==13||ch==14){
			cout<<"0"<<"\n";
		}else if(ch==11||ch==12){
			int cha=x[2]-x[1];
			if(d>=2*cha){
				int ans=(d/cha+1)*2-2;
				cout<<max(0ll,n-ans+1)<<"\n";
			}else{
				cout<<"0"<<"\n";
			}
		}else{
			for(int i=1;i<=n;++i){
				for(int j=i+3;j<=n;++j){
					int k=i,now=0,cnt=0,res=0;
					while(k<=j){
				//		cout<<k<<" ";
						while(now+c[k+1]<=d){
							if(k>j){
								cnt++;
								break;
							}
							now+=c[k+1];
							k++;
				//			cout<<k<<" ";
							if(k>j){
								cnt++;
								break;
							}
						}
						if(k>j){
							break;
						}
						cnt++;
						k++;					
						now=c[k];
					}
					for(int p=i+1;p<j;++p){
						int cy=c[p];
						c[p]=0;
						c[p+1]+=cy;
						int k1=i,now1=0,cnt1=0;
						while(k1<=j){
					//		cout<<k<<" ";
							while(now1+c[k1+1]<=d){
								if(k1>j){
									cnt1++;
									break;
								}
								now1+=c[k1+1];
								k1++;
					//			cout<<k<<" ";
								if(k1>j){
									cnt1++;
									break;
								}
							}
							if(k1>j){
								break;
							}
							cnt1++;
							k1++;					
							now1=c[k1];
						}
						if(cnt1==cnt){
							res++;
						}
						c[p]=cy;
						c[p+1]-=cy;
					}
					if(res==1){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
}
