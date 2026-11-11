#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,m,a[maxn],s[35][maxn],tp[35],b[maxn],c[maxn],sz,csz,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=30;i++){
		int msk=(1ll<<i);
		for(int j=1;j<=n;j++){
			if((a[j]&msk)!=0)s[i][++tp[i]]=j;
		}
	}
	for(int i=30;i>=0;i--){
		if(tp[i]>=m){
			if(sz==0){
				sz=tp[i];
				for(int j=1;j<=sz;j++)b[j]=s[i][j];
			}
			else{
				csz=0;
				memset(c,0,sizeof(c));
				int it1=1,it2=1;
				while(it1<=tp[i]&&it2<=sz){
					if(s[i][it1]<b[it2])it1++;
					else if(s[i][it1]==b[it2])c[++csz]=b[it2++],it1++;
					else it2++;
				}
				if(csz>=m){
					sz=csz;
					for(int i=1;i<=sz;i++)b[i]=c[i];
				}
			}
		}
	}
	ans=(sz>0?a[b[1]]:0);
	for(int i=1;i<=m;i++)ans=ans&a[b[i]];
	cout<<ans;
	return 0;
}
//rp++
