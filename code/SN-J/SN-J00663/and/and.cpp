//luoqiyuan xianshitieyizhongxue SN-J00663
#include<bits/stdc++.h>
#define int long long
using namespace std;
struct st{
	int x,id;
};
bool cmp(st p,st q){
	return p.x>q.x;
}
int n,m;
int a[200005];
vector<int> e[35];
int ans;
st cnt[20005];
bool f[200005][31];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
		for(int j=31;j>=0;j--){
			if((1LL<<j)<=x){
				x-=(1LL<<j);
				f[i][j]=1;
				e[j].push_back(i);
			}
		}
	}
	int k=1;
	for(int j=31;j>=0;j--){
		if(e[j].size()<m) continue;
		k=j;
		break;
	}
	for(int i=1;i<=n;i++){
		cnt[i].id=i;
		if(f[i][k]) cnt[i].x=1;
		else cnt[i].x=0;
		for(int j=k-1;j>=0;j--){
			if(f[i][j+1]) cnt[i].x++;
			else break;
		}
	}
	sort(cnt+1,cnt+n+1,cmp);
	ans=a[cnt[1].id];
	for(int i=2;i<=m;i++) ans&=a[cnt[i].id];
	int res=0;
	if(m==2){
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++) res=max(res,a[i]&a[i+1]);	
	}
	cout<<max(ans,res);
	return 0;
}
