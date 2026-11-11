#include<bits/stdc++.h>
using namespace std;

const int mn=5e5+2;
int n;
long long m;
long long a[mn];

int check(int x){
	int cnt=1,count=0;
	for(int i=x-1;i>0;i--){
		count=count-a[i]+a[x];
		if(count>m)break;
		cnt++;
	}
	return cnt;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n,ans=1;
	while(l<r){
		int mid=l+(r-l)/2;
		int y=check(mid);
		if(y>ans){
			ans=y;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%d",ans);
	return 0;
}