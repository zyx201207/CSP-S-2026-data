#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		long long sum=0;
		long long cnt1=0;
		for(int j=i-1;j>=1;j--){
			if(sum>=m){
				if(cnt1>cnt){
					cnt=cnt1;
				}
				cout<<cnt+1;
				return 0;
			}
			sum+=a[i]-a[j];
			cnt1++;
		}
		if(cnt1>cnt){
			cnt=cnt1;
		}
	}
	cout<<cnt+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
