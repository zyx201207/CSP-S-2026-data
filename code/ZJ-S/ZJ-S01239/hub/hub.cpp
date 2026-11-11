#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
struct N{
	int x,y;
}mp[1000005];

bool cmp(N a,N b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}

bool theA(){
	if(n%2==0)return false;
	for(int i=1;i<=n/2;i++){
		if(mp[i*2-1].x==i&&mp[i*2-1].y==i+1){
			if(mp[i*2].x==i&&mp[i*2].y==i+n/2+1){
				continue;
			}
		}
		return false;
	}
	return true;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int xx,yy;
			cin>>xx>>yy;
			mp[i].x=min(xx,yy);
			mp[i].y=max(xx,yy);
		}
		sort(mp+1,mp+n+1,cmp);
		if(theA()){
			int xx=n/2-k+4;
			if(xx%4==0)cout<<xx/4+1<<endl;
			else cout<<xx/4+2<<endl;
			continue;
		}
	}
	return 0;
} 
