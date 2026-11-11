#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;

int a[N],ans[N],t[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			t[j]=0;
		}
		for(int j=n;j>=i;j--){
			t[a[j]]++;
			if(t[a[j]]>1){
				x=a[j];
				break;
			}
		}
		for(int j=n;j>=i;j--){
			ans[a[j]]++;
			if(a[j]==x) break;
		}
		x=0;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

