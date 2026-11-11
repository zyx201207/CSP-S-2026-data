#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int pd[500010];
int da[300010];
priority_queue<int> q;
int cnt=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		memset(pd,0,sizeof pd);
		cnt=0;
		for(int j=i;j<=n;j++){
			for(int k=cnt;k>=1;k--) if(pd[k]==a[j]) cnt=k-1;
			pd[++cnt]=a[j];
		}
		for(int k=cnt;k>=1;k--) da[pd[k]]++;
	}
	for(int i=1;i<=m;i++) cout << da[i] << ' ';
	return 0;
}
