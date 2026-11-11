#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
int c[300010];
int d[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[j]=0;
			b[j]=0;
		}
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			if(c[b[j]]!=0){
				for(int k=c[b[j]]+1;k<=j;k++){
					if(k!=j){
						c[b[k]]=0;
					}
					b[k]=0;
				}
			}
			else{
				c[b[j]]=j;
			}
		}
		for(int j=1;j<=n;j++){
			if(b[j]!=0){
				d[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
