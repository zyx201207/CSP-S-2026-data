#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans=0,sum=0;
	for(long long i=a[0];i<=a[n-1];i++){
		int p=m;
		for(long long j=0;j<n;j++){
			if(i-a[j]>=0&&p-i+a[j]>=0){
				p=p-i+a[j];
				sum++;
			}
		}
		ans=max(sum,ans);
		sum=0;
	}
	cout<<ans;
	return 0;
}
