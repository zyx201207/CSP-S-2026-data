#include<bits/stdc++.h>
using namespace std;
int w[500005];
struct Node{
	int k;
	map<int,int> mp;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	Node no[505];
	int a,t;
	for(int i=0;i<n;i++){
		cin>>no[i].k;
		cin>>a>>t;
		no[i].mp[a]=t;
	}
	int x,y;
	for(int i=0;i<q;i++){
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
	}
    return 0;
}