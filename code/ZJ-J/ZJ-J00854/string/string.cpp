#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
int ans,all_sum,a[200005],half_sum,n,cnt,cn,h_sum,q_sum;
char c[200005];
struct node {
	int cnt;
	char value;
}p[200005],g[200005];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];all_sum+=a[i];
	}
	half_sum=all_sum/2;
	for(int i=0,j=1;i<=half_sum;) {
		if(a[j]+i>=half_sum) {
			p[++cnt]={half_sum-i,c[j]};
			break;
		} else {
			p[++cnt]={a[j],c[j]};
		}
		i+=a[j];
		++j;
	}
	for(int i=0,j=n;i<=half_sum;) {
		if(a[j]+i>=half_sum) {
			g[++cn]={half_sum-i,c[j]};
			break;
		} else {
			g[++cn]={a[j],c[j]};
		}
		i+=a[j];
		--j;
	}
	for(int i=1,j=1;i<=cnt;i++) {
		if(j>1&&p[i].value!=g[j-1].value) {
			ans+=min(h_sum-q_sum,p[i].cnt);
//			cout<<min(h_sum-q_sum,p[i].cnt)<<"a6\n";
		}
		q_sum+=p[i].cnt;
		while(j<=cn&&q_sum>=h_sum) {
			if(p[i].value!=g[j].value) {
				ans+=min(q_sum-h_sum,g[j].cnt);
//				cout<<min(q_sum-h_sum,g[j].cnt)<<"\n";
			}
			h_sum+=g[j].cnt;
			++j;
		}
	}
	cout<<ans;
	return 0;
}