#include<bits/stdc++.h>
using namespace std;
int n,m,c,q,x,y,o,Max=INT_MIN,s[10888];
int w[10050],k[508],a[10888],t[10888],d[10008][10008];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>o>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=10000;i++){
		for(int j=1;j<=10000;j++){
			d[i][j]=INT_MAX;
		}
	}
	long long Max=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			s[j]=s[j-1]+t[j];
//			Max=max(Max,a[j]);
            if(a[j]>Max){
            	Max=a[j];
			}
		}
		for(int j=1;j<=k[i];j++){
			for(int p=j+1;p<=k[i];p++){
				d[a[j]][a[p]]=d[a[p]][a[j]]=min(d[a[p]][a[j]],min(d[a[j]][a[p]],s[p]-s[j-1]+t[j]+t[p]));
			}
		}
		for(int j=1;j<=k[i];j++) s[j]=0;
	}
	for(int w=1;w<=Max+1;w++){
		for(int i=1;i<=Max+1;i++){
			for(int j=1;j<=Max+1;j++){
				d[i][j]=min(d[i][j],d[i][w]+d[w][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		if(d[x][y]==INT_MIN) cout<<0<<endl;
		else cout<<d[x][y]<<endl;
	}
	return 0;
}
