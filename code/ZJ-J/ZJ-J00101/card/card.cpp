#include <bits/stdc++.h>
using namespace std;
int b[300005],a[500005],n,m;
int q[500005],c[300005],ed=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int t=1;t<=n;t++){
		ed=0;
		memset(c,0,sizeof c);
		for(int i=t;i<=n;i++){
			if(c[a[i]]!=0){
				for(int j=c[a[i]]+1;j<=ed;j++)c[q[j]]=0;
				ed=c[a[i]];
			}
			else q[++ed]=a[i],c[a[i]]=ed;
		}
		for(int j=1;j<=ed;j++)b[q[j]]++;
	}
	for(int i=1;i<=m;i++)cout << b[i] << ' ';
	return 0;
}
//40