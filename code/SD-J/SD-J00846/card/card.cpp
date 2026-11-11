#include<bits/stdc++.h>
using namespace std;
long long n,m,l;
long long a[500005],b[500005],ans[300005];
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
		b[500005]={0};
		l=1;
		for(int j=i;j<=n;j++){
			b[l]=a[j];
			for(int x=1;x<l;x++){
				if(b[x]==b[l]){
					for(int y=x;y<l;y++){
						a[y]=0;
					}
				} 
			}
		} 
		for(int j=1;j<=m;j++){
			for(int x=1;x<=l;x++){
				if(b[x]==j){
					ans[j]++;
				}
			} 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

