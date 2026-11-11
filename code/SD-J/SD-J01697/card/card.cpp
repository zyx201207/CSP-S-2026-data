#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5;
const int M=5e5+5;
string s;
int n,m,a[N],b[M],f[M],ans[M],len=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		len=0;
		for(int j=i;j<=n;++j){
			
			if(f[a[j]]==0||f[a[j]]>len||b[f[a[j]]]!=a[j]){
				f[a[j]]=++len;
				b[len]=a[j];
			}else{
				len=f[a[j]];
			}
			
		}
		for(int j=1;j<=len;++j){
			++ans[b[j]];
			
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}
