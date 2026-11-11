#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d,e,f,g,ans,aaaa;
struct node{
	ll x,y;
};
node aa[20005][20005];
ll bb[20005];
void dj(){
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	q.push({0,e});
	while(!q.empty()){
		int x=q.top().first,y=q.top().second;
		if(bb[y]<x)continue;
		for(int i=1;i<=b;i++){
			if(bb[i]>bb[y]+aa[y][i].y+)
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>aaaa>>a>>b>>c>>d;
	for(int i=1;i<=b;i++)cin>>aa[i][0];
	for(int i=1;i<=a;i++){
		cin>>e;
		for(int j=1;j<=e;j+=2){
			cin>>f>>g;
			aa[i][f]={e,g};
		}
	}
	for(int i=1;i<=d;i++){
		cin>>e>>f;
		memset(bb,0x3f,sizeof(bb));
		dj();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
