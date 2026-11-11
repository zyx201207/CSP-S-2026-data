#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],q[500005],vis[500005];
bool check(int x){
	for(int i=1;i<=n;i++){
		if(q[i]==x){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int j=i;
		for( ;j<=n;j++){
			q[j]=a[j];
			for(int k=1;k<=j;k++){
				if(q[j]==q[k]){
					for(int l=k;l<=j;l++){
						q[l]=0;
					}
				}
			}
		}	
		for(int r=1;r<=m;r++){
				if(check(r)){
					cout << r;
					vis[r]++;
				}
			}
		for(int ii=1;ii<=n;ii++){
			q[ii]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout << vis[i] << ' ';
	}
	return 0;
}
