#include <bits/stdc++.h>
#define int long long
using namespace std;
void suio(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void fio(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
}
const int N=2e6+5;
int a[N],q[N],c[N];
int n,m,cnt;
int mp[N];
signed main(){
	suio();
	fio();
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int s=1;s<=n;s++){
		for (int i=s;i<=n;i++){
			int k=mp[a[i]];
			if(q[k]==a[i]&&k<=cnt){
				cnt=k-1;
			}
			mp[a[i]]=++cnt;
			q[cnt]=a[i];
		}
		for (int i=1;i<=cnt;i++){
			c[q[i]]++;
		}
		cnt=0;
	}
	for (int i=1;i<=m;i++){
		if(i==m){
			cout<<c[i];
			return 0;
		}
		cout<<c[i]<<" ";
	}
	return 0;
}

