#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int lst[N],cnt[N],a[N],h[N],c[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n>=2e4){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int gs=0;
		for(int i=1;i<=n;i++){
			int pos=i;
			while(a[pos]==a[i]){
				pos++;
			}
			c[++gs]=a[i];
			h[gs]=pos-i;
			i=pos-1;
		}
		for(int i=1;i<=gs;i++){
			lst[c[i]]=i;
		}
		for(int i=1;i<=gs;i++){
			for(int j=i;j<=gs;j++){
				if(lst[c[j]]>=i){
					j=lst[c[j]];
				}
				cnt[c[j]]++;
				cnt[c[j]]+=h[j];
			}
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(lst[a[j]]>=i){
				j=lst[a[j]];
			}
			cnt[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 

