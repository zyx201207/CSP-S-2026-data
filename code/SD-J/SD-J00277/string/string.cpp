#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;
int n;
pair<int,char> p[MAXN];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i].first>>p[i].second;
	if(n==1){cout<<0<<endl;return 0;}
	if(n==2){
		if(p[1].second==p[2].second)cout<<0<<endl;
		else cout<<abs(p[1].first-p[2].first)<<endl;
		return 0;
	}
	pair<int,char> ft=p[1],bk=p[n];
	int ans=0;
	for(int ff=2,bf=n-1;ff<=bf+1;){
		ans+=(ft.second!=bk.second)*min(ft.first,bk.first);
		if(ft.first>bk.first){
			ft.first-=bk.first;
			bk=p[bf--];
		}
		else if(ft.first<bk.first){
			bk.first-=ft.first;
			ft=p[ff++];
		}
		else ft=p[ff++],bk=p[bf--];
	}
	cout<<ans<<endl;
	return 0;
}

