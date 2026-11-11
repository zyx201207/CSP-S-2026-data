#include <bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cin>>n>>m;
	int q[n+1],goat[m+1]={0};
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	for(int N=0;N<n;N++){
		int ing[n+1]={0,0};
		for(int i=1;i<=n-N;i++){
			ing[i]=q[i+N];
			for(int j=1;j<i;j++){
				if(ing[i]==ing[j]){
					for(int o=j;o<i;o++){
						ing[o]=0;
						
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n-N;j++){
				if(ing[j]==i){
					goat[i]++;
					//cout<<'2'<<' '<<i<<j;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<goat[i]<<' ';
	}
	return 0;
}
