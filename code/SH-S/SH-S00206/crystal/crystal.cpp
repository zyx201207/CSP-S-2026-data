#include<bits/stdc++.h>
#define N 500010
#define ll long long
using namespace std;
int n,ans,siz,b[N];
ll m,a[N];
map<ll,int>mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in" ,"r",stdin );
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll tmp;
	for(int i=1;i<=n;i++){
		cin>>tmp;
		if(!(mp[tmp]++))a[++siz]=tmp;
	}
	sort(a+1,a+siz+1);
	for(int i=1;i<=siz;i++)b[i]=mp[a[i]];
	ans=b[0];
	for(int i=2;i<=siz;i++){
		int num=b[i];
		ll c=m;
		for(int j=i-1;j>0;j--){
			int ss=b[j];
			ll mm=a[i]-a[j];
			if(c>(1LL*ss*mm)){
				c-=1LL*ss*mm;
				num+=ss;
				continue;
			}
			else{
				num+=c/mm;
				break;
			}
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}
