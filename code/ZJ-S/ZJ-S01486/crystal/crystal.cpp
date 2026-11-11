#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,sum,f;
long long a[500005],b[500005],c[500005];

bool check(int x,int y){
	if(c[x]-b[y]*(y-x+1)-c[y+1]<=m) return 1;
	else return 0; 
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--){
		b[i]=a[n]-a[i];
	}
	for(int i=n-1;i>=1;i--){
		c[i]=b[i]+c[i+1];
	}
	for(int i=1;i<=n;i++){
		int left=1,right=i;
		while(left<=right){
			int mid=(left+right)/2;
			if(check(mid,i)){
				ans=i-mid+1;
				right=mid-1;
			}
			else left=mid+1;
		}
		sum=max(sum,ans);
	}
	cout<<sum;
	return 0;
}