#include<bits/stdc++.h>
using namespace std;	
unsigned long long m,n,a[600005],b[400005][2],c[400005][2],v[500005],g[400005];
bool s[600005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]][0]++;
		b[a[i]][1]=i;
	}
	/*for(int i=1;i<=n;i++){
		cout<<b[a[i]][1]<<endl;
	}*/
	for(int i=1;i<=n;i++){
		long long cnt=0;
		for(int j=1;j<=n;j++)v[i]=0;
		for(int j=1;j<=n;j++)s[i]=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]][0]>1){
				cnt++;
				v[cnt]=a[j];
				g[a[j]]++;
				j=b[a[j]][1];
				
			}
			else{
				cnt++;
				v[cnt]=a[j];
				g[a[j]]++;
			}
		}
		b[a[i]][0]--;
	}	
	for(int i=1;i<=m;i++)cout<<g[i]<<" ";
	return 0;
}
