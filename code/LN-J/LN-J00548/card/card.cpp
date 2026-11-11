//有一个jiankao so beautiful!
#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
const int MAXM=300005;

int a[MAXN],st[MAXN],tm_st[MAXN],pos[MAXM];
long long ans[MAXM];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(pos,-1,sizeof(pos));
	int top=0;
	for(int i=n;i>=1;i--){
		int x=a[i];
		int t=n-i+1;
		if(pos[x]==-1)
		{
			++top;
			st[top]=x;
			tm_st[top]=t;
			pos[x]=top;
		}
		else{
			int idx=pos[x];
			for(int j=idx;j<=top;j++){
				int y=st[j];
				ans[y]+=t-tm_st[j];
				pos[y]=-1;
			}
			top=idx-1;
			++top;
			st[top]=x;
			tm_st[top]=t;
			pos[x]=top;
		}
	}
	for(int i=1;i<=top;i++){
		int y=st[i];
		ans[y]+=n-tm_st[i]+1;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
    return 0;
}
