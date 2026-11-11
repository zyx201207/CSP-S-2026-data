#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	
	long long n,m,maxn=-1;
	cin>>n>>m;
	long long arr[200010];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(m=2){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				long long o=arr[i]&arr[j];
				maxn=max(maxn,o);
			}
		}
	}
	cout<<maxn;
	return 0;
}
