#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int most=-1;
	for(int i=0;i<n;i++){
		while(m--){
			int c=1;
			for(int j=i+c;j<n;j++){
				int r=arr[i]|arr[j];
				if(r>most){
					most=r;
				}
			}
			c++;
		}
	}
	cout<<most;
	return 0;
} 
