#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],maxx,k[500005];
int main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int s[500005]={0},top=1;
		for(int j=i;j<=n;j++){
			for(int k=1;k<top;k++){
				if(s[k]==a[j]){
					top=k;
				}
			}
			s[top++]=a[j];
		}
		for(int j=1;j<top;j++){
			k[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<k[i]<<" ";
	}
	return 0;
} 
