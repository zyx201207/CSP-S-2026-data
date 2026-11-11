#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=300+5,M=2e6+5;
int c,T;
int n,d;
int a[M],fa[N],cnt[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c<=12&&c>=11){
			if(n==1){
				cout<<0<<'\n';
			}
			else{
				int len=0;
				for(int i=1;i<n;i++){
					if((a[2]-a[1])*i>d){
						len=i;
						break;
					}
				}	
				if(len>2){
					cout<<n-2*len+3<<'\n';
				}
				else{
					cout<<0<<'\n';
				}
			}
		}
		else if(c<=14&&c>=13){
			int ans=0;
			int pos;
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
					pos=i;
					break;
				}
			}
			int now=n+1;
			if(pos==1){
				cout<<0<<'\n';
				continue;
			}
			for(int i=pos+2;i<=n;i++){
				if(a[i]-a[pos-1]>d){
					now=i;
				}
			}
			for(int i=1;i<pos;i++){
				if(a[pos-1]-a[i]<=d&&i!=pos&&a[pos+1]-a[i]>d){
					ans+=now-1-pos;
				}
				else if(a[pos+1]-a[i]<=d&&a[pos+2]-a[i]>d){
					ans+=n-now+1;
				}
			}
			cout<<ans<<'\n';
		}
		else{
			for(int i=1;i<=n;i++){
				int l=i,r=n+1;
				while(l<r-1){
					int mid=l+r>>1;
					if(a[mid]-a[i]>d){
						r=mid;
					}
					else{
						l=mid;
					}
				}
				fa[i]=l;
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				if(i==fa[i]){
					continue;
				}
				int la=i;
				for(int j=fa[i];j<=n;j=fa[j]){
					if(j==fa[j]){
						break;
					}
					if(j!=la+1){
						if(j!=la+2){
							int k1=j,k2=j-1,k3=j-2;
							int cnt1=0,cnt2=0,cnt3=0;
							for(int l=j+1;l<=n;l++){
								if(l>fa[k1]){
									k1=fa[k1];
									if(k1==fa[k1]){
										break;
									}
									cnt1++;
								}
								if(l>fa[k2]){
									k2=fa[k2];
									if(k2==fa[k2]){
										break;
									}
									cnt2++;
								}
								if(l>fa[k3]){
									k3=fa[k3];
									if(k3==fa[k3]){
										break;
									}
									cnt3++;
								}
								if(cnt1==cnt2&&cnt1!=cnt3){
									cnt[i][l]++;
								}
							}	
						}
						else{
							int k1=j,k2=j-1;
							int cnt1=0,cnt2=0;
							for(int l=j+1;l<=n;l++){
								if(l>fa[k1]){
									k1=fa[k1];
									if(k1==fa[k1]){
										break;
									}
									cnt1++;
								}
								if(l>fa[k2]){
									k2=fa[k2];
									if(k2==fa[k2]){
										break;
									}
									cnt2++;
								}
								if(cnt1==cnt2){
									cnt[i][l]++;
								}
							}
						}
					}
					la=j;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+2;j<=n;j++){
	//				cout<<cnt[i][j]<<' ';
					ans+=(cnt[i][j]==1);
					cnt[i][j]=0;
				}
	//			cout<<endl;
			}
			cout<<ans<<'\n';	
		}
		
	}
	return 0;
}
//0 1
//8 3
//0 1 2 4 8 10 11 13


