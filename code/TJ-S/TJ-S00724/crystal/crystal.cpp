#include<bits/stdc++.h>
using namespace std;
int pow(long long n,long long m){
	long long sum=0;
	long long a[100005];
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int j=1;j<=n;++j){
		for(int k=0;k<=n;++k){
			if(a[k]+1==a[j]){
			a[k]+=1;
			sum++;
			if(sum==m){
				break;
				}
			}
		}
	}
	
}
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
} 
