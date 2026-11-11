#include<bits/stdc++.h>
#define ll long long
#define F(l,r,i) for(int i=l;i<=r;i++)
#define Fa(l,r,i) for(int i=r;i>=l;i--)
using namespace std;
ll n,m,a[500010],ans[500010],box[300010],cnt[300010],mp[300010];
bool flag=true;
signed main(){
	//freopen("card6.in","r",stdin);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	F(1,n,i){
		cin>>a[i];
		box[a[i]]=i;
		cnt[a[i]]++;
		if(cnt[a[i]]==1) mp[a[i]]=i;
		if(a[i]<a[i-1]) flag=false;
	}
	if(flag){
		F(1,m,i) cout<<box[i]<<" ";
		return 0;
	}
	else{
		F(1,m,i){
			ll now=mp[i];
			while(now<=n){
				ans[a[now]]+=cnt[i];
				now=box[a[now]]+1;
			}
		}
		F(1,m,i) cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}
