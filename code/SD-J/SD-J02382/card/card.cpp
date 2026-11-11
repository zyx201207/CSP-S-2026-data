#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200005],b[200005],c[200005],sum;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		sum=0;
		for(int j=1;j<=i;j++){
			if(c[a[j]]==1) c[a[j]]=j;
			else{
				sum=j;
				c[a[j]]=j;
			}
		}
	}
	return 0;
}
