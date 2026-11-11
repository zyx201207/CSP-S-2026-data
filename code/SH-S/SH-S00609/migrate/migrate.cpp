#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int _,c,n,nxt[N],pre[N],tp[N];
long long d,a[N],ans,mn[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>_;
	while(_--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int k=1;k<=n;k++){
			for(int i=n,j=n;i;i--){
				while(j>=k && a[i]-a[j]<=d) j--;
				pre[i]=j+1;
			}
			tp[k]=1;
			for(int i=k+1;i<=n;i++){
				if(pre[i]<i){
					mn[i]=mn[pre[i]]+1;
					if(mn[pre[i]]==mn[pre[i]+1]){
						if(mn[pre[i]]!=mn[pre[i]+2] && tp[pre[i]]==1 && tp[pre[i]+1]==1)
						tp[i]=2,ans++;
					}
					else if(tp[pre[i]]==2){tp[i]=2,ans++;}
					else if(tp[pre[i]]==1) tp[i]=1;
				}
			}
			for(int j=k;j<=n;j++) tp[j]=mn[j]=pre[j]=0;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
