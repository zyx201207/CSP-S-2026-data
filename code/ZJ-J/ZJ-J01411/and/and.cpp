#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt1,cnt0,ans[200005],maxx,b[200005][35],cnt;
struct node{
	int val,cnt,ft;
}a[200005];
bool cmp(node x,node y){
	if(x.val!=y.val){
		return x.val>y.val;
	}
	return x.ft>y.ft;
}
signed main()
{
	freopen("and.in","r",stdin);//kskbl
	freopen("and.out","w",stdout);//kskbl
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			if(a[i].val&(1<<j)){
				a[i].cnt++;
				a[i].ft=j;
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			if(a[i].val&(1<<j)){
				b[i][j]=1;
			}
			else{
				b[i][j]=0;
			}
		}
	}
	for(int i=30;i>=0;i--){
		cnt=cnt0=0;
		memset(ans,0,sizeof(ans));
		for(int j=1;j<=n;j++){
			if(cnt==m){
				break;
			}
			if(b[j][i]==1){
				ans[++cnt]=a[j].val;
			}
			else{
				cnt0++;
			}
		}
		if(cnt==m){
			int d=(1<<30)-1;
			for(int j=1;j<=m;j++){
				d&=ans[j];
			}
			cout<<d;
			return 0;
		}
	}
	cout<<0;
}
/*
5 3
31 3 1 15 7
*/
/*
nice!!! lets go!!
kskbl dstlrwymyxdJWDJ!
*/
