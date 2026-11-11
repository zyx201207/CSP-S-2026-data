#include<bits/stdc++.h>
using namespace std;
long long n,m,last[300005];
long long a[500005],c[300005];
bool ok[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		c[a[i]]++;
		ok[a[i]]=1;
		for(int j=last[a[i]]+1;j<=n;){
			if(!ok[a[j]]) c[a[j]]++;
			if(j<=last[a[j]]) j=last[a[j]]+1;
			else j++;
		}
		for(int j=1;j<=m;j++) ok[j]=0;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}