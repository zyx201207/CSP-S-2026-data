#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,cnt,maxn=INT_MIN;
int a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=10000){
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			sum=0,cnt=0;
			for(int j=i;j>=1;j--){
				cnt+=abs(a[j]-a[i]);
				if(cnt<=m)sum++;
				else break;
			}
			maxn=max(maxn,sum);
		}
		cout<<maxn;
	}
	else {
		int res=0;
		bool flag=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=i)flag=false;
		}
		sort(a+1,a+n+1);
		if(flag){
			int mid=sqrt(n);
			for(int i=mid;i<=n;i++){
				if(i*(i+1)<=2*m)res=i+1;
				else{
					cout<<res;
					return 0;
				}
			}
			cout<<n;
		}
		else{
			for(int j=n;j>=1;j--){
				if((a[n]-a[j])*(n-j+1)<=m){
					cout<<n-j;
					return 0;
				}
			}
			cout<<n;
		}
	}
	return 0;
} 
