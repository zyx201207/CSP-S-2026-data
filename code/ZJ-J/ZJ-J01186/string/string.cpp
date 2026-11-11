#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
struct node{
	int x;
	char op;
}s[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].x>>s[i].op;
	}
	int l=1,r=n;
	while(l<r){
		//cout<<l<<' '<<r<<'\n';
		int minn=min(s[l].x,s[r].x);
		if(s[l].op==s[r].op){
			s[l].x-=minn;
			s[r].x-=minn;
			if(s[l].x==0){
				l++;
			}
			if(s[r].x==0){
				r--;
			}
		}else{
			ans+=minn;
			s[l].x-=minn;
			s[r].x-=minn;
			if(s[l].x==0){
				l++;
			}
			if(s[r].x==0){
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}