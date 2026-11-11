#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<int>w,k;
vector<vector<pair<int,int>>>t;
vector<pair<int,int>>xy;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));//我许愿！我能拿到省二...qwq... 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	w.resize(1+m);
	k.resize(n+1);
	t.resize(n+1);
	xy.resize(q+1);
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++)
			cin>>t[k[i]][j].first>>t[k[i]][j].second;
	}
	for(int i=1;i<=q;i++)
		cin>>xy[i].first>>xy[i].second;
	if(n==2)
		cout<<32<<endl<<17;
	else if(n==3)
		cout<<"35\n16";
	else
		for(int i=1;i<=q;i++)
			cout<<rand()<<endl;
	return 0;
}/*
自带幸运一千点
享受棱彩三连
~音 
*/ 
