#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],f[N],ans[M],maxe,maxs,cnt;
struct node{
	int s,e;
}t[N];
vector<int> b[M];
bool cmp(node x,node y){
	return x.s<y.s;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		int len=b[i].size();
		if(len>=2){
			for(int j=1;j<len;j++){
				t[++cnt].s=b[i][j-1];
				t[cnt].e=b[i][j];
			}
		}
	}
	sort(t+1,t+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(t[i].s>maxe){
			maxe=t[i].e;
			maxs=t[i].s;
			f[t[i].s]-=t[i].s;
			f[t[i].e]+=t[i].s;
		}else{
			if(t[i].e>maxe){
				maxe=t[i].e;
				maxs=t[i].s;
			}
			f[t[i].s]-=(t[i].s-maxs);
			f[t[i].e]+=(t[i].s-maxs);
		}
	}
	for(int i=1;i<=n;i++){
		f[i]+=f[i-1];
		ans[a[i]]=max(ans[a[i]],i);
	}
	int aa;
	for(int i=1;i<=n;i++){
		ans[a[i]]+=f[i];
		if(i==n) aa=a[i];
	}
	for(int i=1;i<=m;i++){
		if(i!=aa) cout<<ans[i]<<' ';
		else cout<<n<<' ';
	}
	return 0;
}