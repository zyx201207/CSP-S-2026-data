#include<bits/stdc++.h>
using namespace std;
priority_queue<long long>pq[505];
long long n,m,q,cinz,cinx,ciny,a[500005],l[505][505];
vector<long long>e[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	        l[i][j]=1e18;
	for(int i=1;i<=n;i++)
	    l[i][i]=0;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>cinz;
		for(int j=1;j<=cinz;j++){
			cin>>cinx>>ciny;
			e[cinx].push_back(ciny*1000+i);
		}
	}
	for(int i=1;i<=m;i++)
	    for(int j=0;j<e[i].size();j++)
	        for(int k=j+1;k<e[i].size();k++)
	            if(l[e[i][j]%1000][e[i][k]%1000]>e[i][j]/1000+e[i][k]/1000)
	                l[e[i][j]%1000][e[i][k]%1000]=e[i][j]/1000+e[i][k]/1000;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	        if(l[i][j]>l[j][i])
	            l[i][j]=l[j][i];
	for(int k=1;k<=n;k++)
	    for(int i=1;i<=n;i++)
	        for(int j=1;j<=n;j++)
	            if(l[i][j]>l[i][k]+l[k][j])
	                l[i][j]=l[i][k]+l[k][j];
	for(int i=1;i<=q;i++){
		cin>>cinx>>ciny;
		cinz=1e18;
		for(int j=0;j<e[cinx].size();j++)
		    for(int k=0;k<e[ciny].size();k++)
		        if(cinz>l[e[cinx][j]%1000][e[ciny][k]%1000]+e[cinx][j]/1000+e[ciny][k]/1000)
		            cinz=l[e[cinx][j]%1000][e[ciny][k]%1000]+e[cinx][j]/1000+e[ciny][k]/1000;
		cout<<cinz+a[cinx]+a[ciny]<<endl;
	}
	return 0;
}