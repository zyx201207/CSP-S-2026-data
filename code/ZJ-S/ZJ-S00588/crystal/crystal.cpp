#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,maxn,a[N],len[2*N];
vector<int> zjl;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int st=a[2]-a[1],fl=0;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=st) fl=1;
	}
	sort(a+1,a+n+1);
	if(fl==0){
		int cnt=0,sum=0;
		while(sum<=m){
			sum+=cnt*st;
			cnt++;
		}
		cout<<cnt-1<<'\n';
		return 0;
	}
	int l=1;
	for(int r=2;r<=n;r++){
		if(a[r]==a[r-1]) continue;
		len[a[r-1]+N]=r-l;
		zjl.push_back(a[r-1]);
		l=r;
	}
	len[a[n]+N]=n-l+1;
	zjl.push_back(a[n]);
	int siz=zjl.size()-1;
	for(int i=n;i>=1;i--){
		if(a[i]==a[i-1]) continue;
		int sum=0,cnt=0,j=0;
		while(zjl[siz]>a[i]) siz--;
		while(sum+(a[i]-zjl[siz-j])*len[zjl[siz-j]+N]<=m){
			sum+=(a[i]-zjl[siz-j])*len[zjl[siz-j]+N];
			cnt+=len[zjl[siz-j]+N];
			j++;
			if(j>siz) break;
		}
		if(j>siz) {
			maxn=max(cnt,maxn);
			break;
		}
		while(sum+a[i]-zjl[siz-j]<=m){
			sum+=a[i]-zjl[siz-j];
			cnt++;
		}
		maxn=max(cnt,maxn);
	}
	cout<<maxn<<'\n';
	return 0;
}//zjl niu bi