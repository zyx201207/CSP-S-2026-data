#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005],t[300003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		ll bj=i;
		for(int j=i;j<n;j++){
			if(bj!=j){
				for(int k=bj;k<j;k++){
					if(a[j]==a[k]){
						bj=j;
						break;
					}
				}
			}	
		}
		for(int j=bj;j<n;j++){
			t[a[j]]++;
		}
	}
	t[a[n-1]]++;
	for(int i=1;i<=m;i++)cout<<t[i]<<" ";
	return 0;
} 
