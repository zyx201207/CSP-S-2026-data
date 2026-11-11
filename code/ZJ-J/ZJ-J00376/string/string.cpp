#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct yd{
	int n;
	char lt;
}cnt[200010];

int n;
ll len=0,ans=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cnt[i].n>>cnt[i].lt;
		len+=cnt[i].n;
	}
	ll ri=n;
	for(int i=1;i<=n;i++){
		ll add=cnt[i].n;
		while(ri>i && cnt[ri].n<=add){
			add-=cnt[ri].n;
			if(cnt[ri].lt!=cnt[i].lt) ans+=cnt[ri].n;
			ri--;
		}
		if(ri==i) break;
		cnt[ri].n-=add;
		if(cnt[ri].lt!=cnt[i].lt) ans+=add;
	}
	cout<<ans;
	return 0;
}
