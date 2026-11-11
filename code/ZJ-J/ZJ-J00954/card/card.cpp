#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;;
	int a[n+5],b[n+5],c[m+1];
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		b[i] = 0;
	}
	for(int i = 1;i<=m;i++){
		c[i] = 0;
	}
	for(int i = 1;i<=n;i++){
		int size=0;
		for(int j = i;j<=n;j++){
			int y = 0;
			for(int r = 1;r<=size;r++){
				if(b[r]==a[j]){
					size = r;
					y++;
				}
			}
			if(y==0){
				size++;
				b[size] = a[j];
			}
		}
		for(int j = 1;j<=size;j++){
			c[b[j]]++;
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}