#include<bits/stdc++.h>
using namespace std;
long long p,k,sum[1000000000001],n,m,l[1000000000001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	sort(l,l+n);
	for(int i=0;i<n;i++){
		cout<<l[i]<<" ";
	}
	for(int i=0;i<n;i++){
		k=m;
		sum[i]++;
		for(int j=0;j<i;j++){
			if(l[i]==l[j]){
				sum[i]++;
			}
			if(k<=0){
				continue;
			}
			else if(l[j]+m>=l[i]){
				k-=(0-(l[i]-l[j]));
				sum[i]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(p<sum[i]){
			p=sum[i];
		}
	}
	cout<<p;
	return 0;
}
