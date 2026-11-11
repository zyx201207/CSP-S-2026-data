#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],p[500005],s[500005],q[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int hd=0;
		for(int j=1;j<=m;j++)p[j]=0;
		for(int j=i;j<=n;j++){
			if(p[a[j]]!=0){
				while(q[hd]!=a[j]&&hd)p[q[hd--]]--;
			}
			else q[++hd]=a[j],p[a[j]]++;
		}
		while(hd){
			int g=q[hd];
			if(p[g]!=2)p[g]=2,s[g]++;
			hd--;
		}
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<' ';
	return 0;
}
