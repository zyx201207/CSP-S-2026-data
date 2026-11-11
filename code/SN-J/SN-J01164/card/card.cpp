#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500001],b[300001];
long long mp[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long t=1,T=n;
	while(T--){
		int cnt=1;
		for(int i=t;i<=n;i++){
			for(int j=1;j<=cnt;j++){
				if(mp[j]==a[i]){
					cnt=j;
				}
			}
			mp[cnt]=a[i];
			cnt++;
		}
		for(int i=1;i<cnt;i++){
			b[mp[i]]++;
		}
		t++;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
