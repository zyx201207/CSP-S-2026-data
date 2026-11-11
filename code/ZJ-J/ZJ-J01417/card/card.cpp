#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int la[300005];
int cnt[500005];
int main(){
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)if(!la[a[i]])la[a[i]]=i;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
			j=la[a[j]];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}