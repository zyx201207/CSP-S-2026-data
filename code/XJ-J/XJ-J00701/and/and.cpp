#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0){
				sum=a[j];
			}else{
				sum&a[j];
			}
		}
	}cout<<sum;
	
	
} 
