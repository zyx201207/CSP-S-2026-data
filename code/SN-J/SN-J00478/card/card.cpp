#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,a[100010],b[100010];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		b[i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				for(int l=i;i<j;l++){
					a[i]==-1;
				}
			}
		}
		for(int k=1;k<=m;k++){
			for(int v=0;v<n;v++){
				if(a[v]==k){
					b[k-1]++;
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

