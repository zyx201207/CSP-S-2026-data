#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],b[200005],c[200005],q[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			b[j]=0;
		}
		for (int j=i;j<=n;j++){
			b[j]=a[j];
			for (int k=1;k<j;k++){
				if(b[k]==b[j]){
					for (int e=k;e<j;e++){
						b[e]=0;
					}
				}
			}
			
		}
		for (int k=1;k<=n;k++){
				if(b[k]!=0){
					q[b[k]]++;
				}
			}
	}
	for (int i=1;i<=m;i++){
		cout<<q[i]<<' ';
	}
	return 0;
} 
