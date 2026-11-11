#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N];
int main(){
	
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum1=m;
	long long ans=0,cnt=0;
	sort(a,a+1);
	for(int i=1;i<=m;i++){
		int sum=0;
		if(sum1==0){
			break;
		}
		for(int j=i+1;j<=m;j++){
			if(a[i]==a[j]){
				ans++;
			}else{
				if(a[i]+i==a[j]||a[i]-i==a[j]){
					ans++;
					sum1-=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
