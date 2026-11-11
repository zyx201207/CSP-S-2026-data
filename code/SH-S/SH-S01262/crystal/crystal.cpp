#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN=5e5+5;
ll n,m,a[MAXN],idx,ans,maxn;
__int128 minn=1e24+1,a1[MAXN],m1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	m1=m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[i]=a[i];
	}
	sort(a1+1,a1+n+1);
	for(int i=3;i<=n;i++)
		if(a1[i]-a1[i-1]!=a1[i-1]-a1[i-2]) flag=false;
	if(flag){
		for(int i=1;i<=n;i++)
			if((a1[i]-a1[1])*i/2<=m1) ans=i;
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<n;i++){
		m1=m;
		int l=i,r=i+1;
		__int128 cur=a1[r];
		if(a1[r]-a1[l]>m1) continue;
		ans=2;
		m1-=a1[r]-a1[l];
		while(l>1||r<n){
			if(m1<min(cur-a1[l-1],(a1[r+1]-cur)*(r-l+1))) break;
			if(l>1&&cur-a1[l-1]<=(a1[r+1]-cur)*(r-l+1)){
				m1-=cur-a1[l-1];
				l--;
				ans++;
			}else if(r<n){
				m1-=(a1[r+1]-cur)*(r-l+1);
				cur=a1[r+1];
				r++;
				ans++;
			}else break;
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn<<endl;
	return 0;
}
