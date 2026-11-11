#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node{
	int x;char c;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].c;
	int l=1,r=n,ans=0;
	while(l<r){
		int x=a[l].x,y=a[r].x;
		char u=a[l].c,v=a[r].c;
		if(u==v){
			if(x<=y){
				y-=x;
				x=0;
			}else{
				x-=y;
				y=0;
			}
		}else{
			if(x<=y){
				y-=x;ans+=x;
				x=0;
			}else{
				x-=y;ans+=y;
				y=0;
			}
		}
		a[l].x=x;a[r].x=y;
		if(x)r--;
		else l++;
	}
	cout<<ans;
	return 0;
}

