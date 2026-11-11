#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],cnt[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int t=1;t<=n;t++){
		set<int> st;
		for(int j=t;j<=n;j++) st.insert(a[j]);
		for(int s:st) cnt[s]++;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
//12pts;wo bu hui jiu zhi neng da 212pts ba?????????????? wo de yi deng meng!!!
