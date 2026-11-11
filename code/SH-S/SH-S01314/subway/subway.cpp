#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500020],minn;
vector<pair<int,int>>que[500020];
vector<pair<int,int>>vec[500020];
bool check(int i,int j) {
	for(auto qwr : vec[i]) {
		if(qwr.first==j) return 1;
	}
	return 0;
}
int min1(int i,int j) {
	if(i>j) return j;
	return i;
}
int max1(int i,int j) {
	if(i<j) return j;
	return i;
}
int taker1(int i,int j) {
	for(auto qwr:que[i]) {
		if(qwr.first==j) return qwr.second;
	}
	return 0;
}
int taker2(int i,int j) {
	for(auto qwr : vec[i]) {
		if(qwr.first==j) return qwr.second;
	}
	return 0;
}
void conter(int i,int j,int cnt) {
	if(check(i,j)) {
	    if(minn>cnt+taker2(i,j)) minn=cnt+taker2(i,j);
	    return ;
	}
	for(auto qwr:vec[i]) {
		conter(qwr.first,j,cnt+qwr.second);
	}
	return ;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for(int i=1;i<=n;i++) {
		int k,a[500020],t[500020];
		cin>>k;
		for(int j=1;j<=k;j++) {
			cin>>a[j]>>t[j];
			que[a[j]].push_back({i,t[i]});
			for(int l=1;l<j;l++) {
				vec[min1(a[l],a[j])].push_back({max1(a[j],a[l]),t[j]+t[l]});
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if(check(i,j)) {
				continue;
			}
			else {
				minn=1e10;
			    conter(i,j,0);
				vec[i].push_back({j,minn});
			}
		}
	}
	for(int i=1;i<=q;i++) {
		int x,y;
		cin>>x>>y;
		cout<<taker2(min(x,y),max(x,y))+w[x]+w[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
