#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int b[1000000];
int cnt[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=1;
		}
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(b[k]==0) continue;
				if(a[k]==a[j]){
					for(int l=k;l<j;l++){
						if(b[l]==0) continue;
						b[l]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(b[j]==0) continue;
			cnt[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}