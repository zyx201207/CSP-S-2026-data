#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,q,a[10001],maxn=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int l=i-1,r=i+1;
		long long num=1,sum=0;
		int ar;
		while(sum<m){
			if(a[i]-a[r]<=0){
				ar=a[r]-a[i];
			}
			else{
				ar=a[i]-a[r];
			}
			if(l<=0){
				sum+=ar;
				r++;
				num++;
			}
			else if(r>n){
				sum+=a[i]-a[l];
				l--;
				num++;
			}
			else if(a[i]-a[l]==ar){
				sum+=a[i]-a[l];
				l--;
				r++;
				num++;
			}
			else if(a[i]-a[l]<ar){
				sum+=a[i]-a[l];
				l--;
				num++;
			}
			else {
				sum+=ar;
				r++;
				num++;
			}
		}
		if(sum>m)num-=1;
	maxn=max(maxn,num);
	}
	cout<<maxn;
	return 0;
} 
