#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ne[N],c[N],ans[N],tot,num[N],cnt[N],id[N],l[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ne[c[a[i]]]=i;
		c[a[i]]=i;
	}
	for(int i=n;i;i--){
		if(ne[i]) num[i]=num[ne[i]];
		else{
			num[i]=++tot;
			l[tot]=num[i+1];
			id[tot]=a[i];
		}
		cnt[num[i]]++;
	}
	for(int i=tot;i;i--){
		cnt[l[i]]+=cnt[i];
		ans[id[i]]=cnt[i];
//		cout<<"i="<<i<<" cnt="<<cnt[i]<<"\n";
	}
	for(int i=1;i<m;i++) cout<<ans[i]<<" ";
	cout<<ans[m];
	return 0;
}
