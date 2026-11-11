#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],t[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]!=a[j+1])
			    t[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
