#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long m,n,maxx=0;
long long ans=((1<<30)-1);
struct aa{
	long long a,c;
}h[N];
bool cmp(aa f,aa s){
	return f.a>s.a;
}
signed main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
   		cin>>h[i].a;
   	}
   	if(m==1){
   		for(int i=1;i<=n;i++)maxx=max(maxx,h[i].a);
   		cout<<maxx;
   		return 0;
    }
    if(m==n){
    	maxx=h[1].a;
    	for(int i=2;i<=n;i++){
    		maxx=maxx&h[i].a;
		}
		cout<<maxx;
		return 0;
	}
   	sort(h+1,h+1+n,cmp);
   	for(int i=1;i<=m;i++){
   		ans=ans&h[i].a;
	}
   cout<<ans;
   return 0;
}

