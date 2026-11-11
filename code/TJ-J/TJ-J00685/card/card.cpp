#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,m,a[N],b[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			for(int k=j;k<=n;k++) if(a[j]==a[k]) j=k;
			cnt++;
			b[cnt]=a[j];
		}
		for(int j=1;j<=cnt;j++){
			t[b[j]]++;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}
