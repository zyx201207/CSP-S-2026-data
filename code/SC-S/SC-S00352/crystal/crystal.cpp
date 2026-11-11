#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=INT_MIN;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		long long l=1,r=i,mid,f=0;
		while(l<mid&&mid<r){
			mid=(l+r)/2+1;
			int num=0; 
			for(int j=i;j>=mid;j--){
				num+=a[i]-a[j];
				if(num>m){l=mid;break;}
			}
			if(num<m)r=mid;
			if(num==m){maxn=max(maxn,i-mid-1);f=1;break;}
		}
		if(f==0)maxn=max(maxn,i-mid-1);
	}
	cout<<maxn;
	return 0;
} 