#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N];
long long b[N];
int ans=1;
long long cha;
void solve1(){
	long long sum=0;
	for(int j=1; j<=n-1; j++){
		sum+=(cha*j);
		if(sum>m){
			ans=max(ans,j);
			break;
		}
	}
	cout<<ans;
}
void solve2(){
	sort(a+1,a+1+n);
	for(int i=2; i<=n; i++){
		b[i-1]=a[i]-a[i-1];
	}
	for(int i=1; i<=n-1; i++){
		long long sum=0;
		for(int j=i; j<=n-1; j++){
			sum+=(b[j]*(j-i+1));
			if(sum>m){
				ans=max(ans,j-i+1);
				break;
			}
			
		}
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool bj=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	cha=a[2]-a[1];
	for(int i=3; i<=n; i++){
		if(a[i]-a[i-1]!=cha){
			bj=1;
			break;
		}
	}
	if(!bj){
		solve1();
	}
	else{
		solve2();
	}
	return 0;
}
