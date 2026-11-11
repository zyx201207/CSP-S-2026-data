#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],k,a[500010],t[500010],s,e,l[500010][500010],dd=INT_MAX,dt,h;
typedef pair<int,int> pi;
priority_queue<pi,vector<pi>,greater<pi>> pq;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=2;j<=n;j++){
			l[a[j-1]][a[j]]=t[j-1]+t[j];
			l[a[j]][a[j-1]]=t[j-1]+t[j];
		}
	}
	for(int r=1;r<=q;r++){
		cin>>s>>e;
		dd=w[s];
		int ws=w[s];
		pq.push({ws,s});
		while(!pq.empty()){
			dt=pq.top().first;
			h=pq.top().second;
			pq.pop();
			if(dt+l[s][e]<dd){
			    dd=dt+l[s][e];
				pq.push({dd,s});
				
			}
		}
		cout<<d;
	}
    return 0;
}

