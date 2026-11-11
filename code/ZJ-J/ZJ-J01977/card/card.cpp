#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,ans[N],a[N],rm[N],b[N];
char c[N];

signed main(){
	freopen("card2.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5000){
		for(int i=1;i<=n;i++){
			memset(rm,0,sizeof rm);
			memset(b,0,sizeof b);
			for(int j=i;j<=n;j++){
				if(b[a[j]] && !rm[b[a[j]]]){
					for(int k=b[a[j]];k<j;k++) rm[k]=1;
				}
				else b[a[j]]=j;
//				int flag=0;
//				for(int k=i;k<j;k++){
//					if(flag) rm[k]=1;
//					else if(!rm[k] && a[k]==a[j]) flag=1,rm[k]=1;
//				}
			}
			for(int j=i;j<=n;j++){
				if(!rm[j]) ans[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	return 0;
}
