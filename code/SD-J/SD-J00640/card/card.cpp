#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,a[N],ans[N],b[N];
signed main(){
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
		for(int j=1,k=i;k<=n;j++,k++){
			b[j]=a[k];
		}
		for(int j=1;j<=n-i+1;j++){
			bool f=true;
			for(int k=1;k<j;k++){
				if(b[k]==b[j]||f==false) b[k]=0,f=false;
			}
		}
		for(int j=1;j<=n-i+1;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

