#include<bits/stdc++.h>
using namespace std;
int w[500010];
struct node{
	long long a,t;
}a1[500010],a2[500010];
bool sf1[500010],sf2[500010],s1t[500010],s2t[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k1,k;
	long long hc=1000000000000000;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	cin>>k1;
	for(int i=1;i<=k1;i++){
		cin>>a1[i].a>>a1[i].t;
		sf1[a1[i].a]=1;
		s1t[a1[i].a]=a1[i].t;
	}

	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>a2[i].a>>a2[i].t;
		sf2[a2[i].a]=1;
		s2t[a2[i].a]=a2[i].t;
		for(int j=1;j<=k1;j++)
			if(a2[i].a==a1[j].a)
				hc=min(hc,a2[i].t+a1[j].t);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ww=w[x]+w[y];
		long long s1e1=s1t[x]+s1t[y];
		long long s1e2=s1t[x]+s2t[y]+hc;
		long long s2e1=s2t[x]+s1t[y]+hc;
		long long s2e2=s2t[x]+s2t[y];
		if(sf2[x]==1&&sf2[y]==1&&sf1[x]==0&&sf1[y]==0)
			cout<<s2e2+ww;
		if(sf2[x]==1&&sf2[y]==1&&sf1[x]==1&&sf1[y]==0)
			cout<<min(s1e2,s2e2)+ww;
		if(sf2[x]==1&&sf2[y]==1&&sf1[x]==0&&sf1[y]==1)
			cout<<min(s2e1,s2e2)+ww;
		if(sf2[x]==1&&sf2[y]==1&&sf1[x]==1&&sf1[y]==1)
			cout<<min({s2e1,s2e2,s1e1,s1e2})+ww;
		if(sf2[x]==0&&sf2[y]==0&&sf1[x]==1&&sf1[y]==1)
			cout<<s1e1+ww;
		if(sf2[x]==0&&sf2[y]==1&&sf1[x]==1&&sf1[y]==1)
			cout<<min(s1e1,s1e2)+ww;
		if(sf2[x]==1&&sf2[y]==0&&sf1[x]==1&&sf1[y]==1)
			cout<<min(s2e1,s1e1)+ww;
		if(sf2[x]==1&&sf2[y]==0&&sf1[x]==0&&sf1[y]==1)
			cout<<s2e1+ww;
		if(sf2[x]==0&&sf2[y]==1&&sf1[x]==1&&sf1[y]==0)
			cout<<s1e2+ww;
		cout<<"\n";
	}
	return 0;
}