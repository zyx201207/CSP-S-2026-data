#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
ll n,m,a[maxn],nxt[maxn];
int ans;
int mp(int pos){
	int ans=0,np=pos-1;
	ll cnt=0,cha=0;
	while(np>=1){
		cha+=nxt[np];
		if(cnt+cha<=m){
			cnt+=cha;
			np--;
		}
		else
			break;
	}
	return pos-np;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		nxt[i-1]=a[i]-a[i-1];
	}
	if(n>=5000){
		int left=1,right=n;
		while(left<right){
			int mid=left+right>>1;
			if(mp(mid)==mid) left=mid+1;
			else right=mid-1;
		}
		cout<<left-1<<"\n";
	}
	else
	{
		for(int i=1;i<=n;i++){
			ans=max(ans,mp(i));
		}
		cout<<ans<<"\n";
	}
	
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
