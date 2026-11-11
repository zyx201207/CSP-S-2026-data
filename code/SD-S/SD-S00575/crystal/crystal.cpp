#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],p[500010],ans=0;
map<long long,long long>ma;
int main(){
	/*
	RP++
	不会啊...qwq
	评测机先生，给点分吧，求求啦...awa
	*/
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=(int)n;i++){
		cin>>a[i];
		ma[a[i]]++;
	}
	for(auto x:ma)
		ans=max(ans,x.second);
	sort(1+a,1+a+n);
	for(int i=2;i<=(int)n;i++)
		if(m>=(i-1)*(a[i]-a[i-1])){
			ans=max(ans,(long long)i);
			m-=(i-1)*(a[i]-a[i-1]);
		}
		else
			break;
	cout<<ans;
	return 0;
}/*
一钻一彩一质变
轮回神运成仙
~雪 
*/
