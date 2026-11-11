#include<bits/stdc++.h>
using namespace std;
long long n,m; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	long long a[n];
	for(long long i=1;i<=m;i++){
		for(long long j=0;j<n;j++){
			if(a[j]==i){
				cout<<j+1<<" ";
				break;
			}
		}
	}
	return 0;
}
