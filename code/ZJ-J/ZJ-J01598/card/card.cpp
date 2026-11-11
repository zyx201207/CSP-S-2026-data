#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,ans=1;
LL a[500005];
LL b[300005];
LL c[300005];
LL d[300005];
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
		for(int j=1;j<=n;j++){
			b[j]=1e18;
		}
		b[a[i]]=1;
		d[1]=a[i];
		ans=1;
		for(int j=i+1;j<=n;j++){
			if(b[a[j]]>ans){
				ans++;
				b[a[j]]=ans;
				d[ans]=a[j];
			}
			else{
				ans=b[a[j]];
			}
		}
		for(int j=1;j<=ans;j++){
			c[d[j]]++;
		}			
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
