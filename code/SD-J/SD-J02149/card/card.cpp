#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,m,a[500005],p[500005],t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(p,0,sizeof p);
		ll cnt=0;
		for(int j=i;j<=n;j++){
			bool flag=0;
			for(int k=1;k<=cnt;k++){
				if(p[k]==a[j]){
					flag=1;
				}
				if(flag){
					p[k]=0;
					cnt--;
				}
			}
			p[++cnt]=a[j]; 
		}
		for(int j=1;j<=cnt;j++)t[p[j]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
}
//RP+=INF
