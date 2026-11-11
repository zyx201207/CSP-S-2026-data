#include<bits/stdc++.h>
using namespace std;
#define int long long

int ison[3005],cnt[3005],a[3005],pre[5005][3005],last[3005];
//pre[i][j]:preh of the begin i cardz Point is j

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//for(int j=1;j<=m;j++)pre[i][j]=pre[i-1][j];
		pre[i][a[i]]++;
	}
	
	for(int i=0;i<n;i++){
		//for(int j=1;i<=m;j++)last[j]=i;
		for(int j=i+1;j<=n;j++){
			if(!ison[a[j]]){
				ison[a[j]]++;
			}else{
				int k=j-1;
				while(a[k]!=a[j]){
					ison[a[k]]=0;
					k--;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(ison[j]){
				ison[j]=0;
				cnt[j]++;
			}
		}
	}
	for(int j=1;j<=m;j++){
		cout<<cnt[j]<<" ";
	}
	return 0;
}
