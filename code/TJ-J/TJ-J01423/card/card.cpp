#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],pot[300005];
int ans[500005];
int m[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,M;
	scanf("%lld%lld",&n,&M);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int t=1;t<=n;t++){
		int len=0;
		memset(pot,0,sizeof(pot));
		memset(m,0,sizeof(m));
		for(int i=t;i<=n;i++){
			if(pot[a[i]]){
				for(int j=pot[a[i]]+1;j<=len;j++) pot[m[j]]=0;
				len=pot[a[i]];
				//cout<<a[i]<<" "<<pot[a[i]]<<endl;
//				for(int j=1;j<=len;j++) cout<<m[j]<<" ";
//				cout<<endl;
			}else{
				m[++len]=a[i];
				pot[a[i]]=len;
			}
		}
//		for(int i=1;i<=len;i++) cout<<m[i]<<" ";
//		cout<<endl;
		for(int i=1;i<=len;i++) ans[m[i]]++;
	}
	for(int i=1;i<=M;i++) printf("%lld ",ans[i]);
	return 0;
}
