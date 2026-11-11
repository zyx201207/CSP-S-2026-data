#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
long long m,n,a[N],ans[N],fl,b[N],c[N],v[N],w[N],s[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])fl=1;
	}
	if(fl==0){
		for(int i=2;i<=n;i++){
			if(a[i-1]!=a[i]){
				ans[a[i-1]]=i-1;
			}
		}
		for(int i=1;i<=n;i++){
			if(ans[i])cout<<ans[i]<<" ";
		}
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof v);
		memset(w,0,sizeof w);
		for(int j=i;j<=n;j++){
			if(v[a[j]]==1){
				s[w[a[j]]]--;
				s[j]++;
				w[a[j]]=j;
			}
			v[a[j]]=1;
			w[a[j]]=j;
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i]+s[i-1];
		c[a[i]]=min(c[a[i]],i-b[i]);
	}
	for(int i=1;i<=m;i++){
		if(c[i])cout<<c[i]<<" ";
	}
	return 0;
}
