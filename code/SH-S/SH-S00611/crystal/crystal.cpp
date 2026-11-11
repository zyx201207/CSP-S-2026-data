#include<bits/stdc++.h>
using namespace std; 
int n;
long long m,a[500005],p[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long sum=0;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++){
		p[i]=a[i]-a[i-1];
		sum+=p[i];
	}
	if(sum<=m){
		cout<<n;
		return 0;
	}
	int l=1,r=n,cnt=n;
	while(l<r){
		if(sum>m){
			if(p[r]>=p[l]){
				r--;
				cnt--;
				sum-=p[r];
			}
			else{
				l++;
				cnt--;
				sum-=p[l];
			}
		}
		else break;
	}
	cout<<cnt;
	return 0;
}
