#include<bits/stdc++.h>
#define IOSO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
#define QwQ return 0;
#define int long long
using namespace std;
const int N=2e5+10;
struct node{
	int w;
	char c;
}a[N];
signed main(){
	IOSO;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].w>>a[i].c;
	}
	int l=1,r=n;
	int ans=0;
	while(l<r){
		if(a[l].c!=a[r].c){
			int minn=min(a[l].w,a[r].w);
			ans+=minn;
			a[l].w-=minn;
			a[r].w-=minn;
			if(a[l].w<=0){
				l++;
			}
			if(a[r].w<=0){
				r--;
			}
		}else{
			int minn=min(a[l].w,a[r].w);
			a[l].w-=minn;
			a[r].w-=minn;
			if(a[l].w<=0){
				l++;
			}
			if(a[r].w<=0){
				r--;
			}
		}
	}
	cout<<ans<<endl;
	QwQ;
}