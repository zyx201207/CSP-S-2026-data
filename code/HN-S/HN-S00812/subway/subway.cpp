#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,w[100005],a[1000],k[500][200005],t[500][200005],xr,yr;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<a[i];j++) cin>>k[i][j]>>t[i][j];	
	}
	for(int i=0;i<q;i++){
		cin>>xr>>yr;
		for(int j=0;j<n;j++){
			for(int h=0;h<a[j];h++){
				if(xr==k[j][h]) 
			}
		}
	}
	return 0;
}
