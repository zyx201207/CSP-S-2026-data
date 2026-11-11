#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
vector<int> e[N];
pair<int,int> a[N];
bool b[N];
int d[N],cd[N],ud[N];
void fg(int x,int fa,int ban){
	d[x]=cd[x]=ud[x]=0;
	for(auto y:e[x]){
		if(y==fa || y==ban) continue;
		fg(y,x,ban);
		if(d[y]+1>d[x]) cd[x]=d[x],d[x]=d[y]+1;
		else if(d[y]+1>cd[x]) cd[x]=d[y]+1;
	}
	return;
}
int r1,s1,r2,s2;
void ug(int x,int fa,int u){
	ud[x]=u;
	int s=max(d[x],max(cd[x],ud[x]));
	if(s<s1) r1=x,s1=s;
	for(auto y:e[x]){
		if(y==fa) continue;
		ug(y,x,u+1);
	}
	return;
}
void ug1(int x,int fa,int u){
	ud[x]=u;
	int s=max(d[x],max(cd[x],ud[x]));
	if(s<s2) r2=x,s2=s;
	for(auto y:e[x]){
		if(y==fa) continue;
		ug1(y,x,u+1);
	}
	return;
}
void dg(int x,int fa,int ban){
	d[x]=0;
	for(auto y:e[x]){
		if(y==fa || y==ban) continue;
		dg(y,x,ban);
		d[x]=max(d[x],d[y]+1);
	}
	return;
}
bool check(int ch){
	for(int i=1;i<n;i++){
		fg(a[i].first,0,a[i].second);
		r1=a[i].first;s1=d[a[i].first];
		r2=a[i].second;s2=d[a[i].second];
		for(auto j:e[a[i].first]){
			if(j==a[i].second) continue;
			if(d[j]+1==d[a[i].first]) ug(j,a[i].first,cd[a[i].first]+1);
			else ug(j,a[i].first,d[a[i].first]+1);
		}
		fg(a[i].second,0,a[i].first);
		for(auto j:e[a[i].second]){
			if(j==a[i].first) continue;
			if(d[j]+1==d[a[i].second]) ug1(j,a[i].second,cd[a[i].second]+1);
			else ug1(j,a[i].second,d[a[i].second]+1);
		}
		dg(r1,0,a[i].second);
		dg(r2,0,a[i].first);
		int cnt=0;
		for(int j=1;j<=n;j++) if(d[j]>=ch || j==r1 || j==r2) cnt++;
		if(cnt<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
			a[i]={x,y};
		} 
		int l=1,r=n,mid;
		while(l<r){
			mid=l+r>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		cout<<mid<<"\n";
		for(int i=1;i<=n;i++) e[i].clear();
	}
	return 0;
}
