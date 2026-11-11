//mahaoyu yuan dong er zhong SN-S00345
#include<bits/stdc++.h>
using namespace std;
long long n,m,yangben=0,sss,mn;
long long a[100000000];
long long sum[10000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int k=1;k<n;k++){
		yangben=a[k];
		mn=m;
		for(int i=k-1;i>=0;i++){
			if(mn<(yangben-a[i])){
				break;
			}
			mn=mn-(yangben-a[i]);
			sum[k]++;
		}
		cout<<sum[k]<<endl;
		for(int i=k;i<n;i++){
			if(a[i]==yangben){
				sum[k]++;
			}
		}   
	}
	for(int i=0;i<n-1;i++){
		sss=max(sum[i],sum[i+1]);
	}
	cout<<sss;
	return 0;
}
