#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N];
bool cmp(long long x,long long y){return x<y;}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==m){
		long long ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(n-1==m){
		long long ans=a[1],ans1=0;
		for(int i=2;i<=n;i++)ans&=a[i];
		for(int i=1;i<=n;i++){
			long long sum=ans|a[i];
			if(sum>ans1){
				ans1=sum;
			}
		}
		cout<<ans1;
		return 0;		
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long sum=a[i]&a[j];
				if(sum>ans)ans=sum;
			}
		}
		cout<<ans;
		return 0;
	}
	long long l=n-1,ans=a[n];
	for(int i=1;i<m;i++){
		ans&=a[l];
		l--;
	}
	cout<<ans;
	return 0;
}
