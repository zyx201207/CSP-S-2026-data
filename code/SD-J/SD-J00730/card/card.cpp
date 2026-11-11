#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],b[3005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int c[3005],d[3005];
		for(int i=1;i<=3000;i++){
			c[i]=0;
			d[i]=0;
		} 
		for(int j=i;j<=n;j++){
			if(c[a[j]]!=0){
				for(int g=d[a[j]];g<j;g++){
					c[a[g]]--;
				}
			}
			c[a[j]]++;
			d[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			cout<<c[j]<<" ";
			b[j]+=c[j];
		}
		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

