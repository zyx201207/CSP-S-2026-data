#include<bits/stdc++.h>
using namespace std;
long long c,r;
long long a[2011001],t[2000011];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>r;
	for(int i=1;i<=r;i++){
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		int n,m;
		cin>>n>>m;
		for(int j=1;j<=n;j++){
			cin>>t[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(t[k]-t[j]<=m)a[j]++;
				else break;
			}
		}
		
	}
	return 0;
}	
