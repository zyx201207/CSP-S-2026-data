#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[400010],t[400010],c[400010],ans[400010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		int x=-1;
		for(int j=i;j<=n;j++){
			t[a[j]]++;
			if(t[a[j]]==2){
				for(int l=1;l<=m;l++){
					t[l]=0;
				}
				t[a[j]]=1;
				x=j;
			}
		}
		if(x==-1) x=i;
		for(int j=x;j<=n;j++){
			ans[a[j]]++;
		}
		for(int j=1;j<=m;j++) t[j]=0;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
