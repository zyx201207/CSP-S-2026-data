#include<bits/stdc++.h> 
using namespace std;
const int N=2e5+5;
int n,m;
long long ans=0;
long long num[N],dp[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	if(m<=2){
		sort(num+1,num+n+1);
		if(m==1)
			cout<<num[1];
		else
			cout<<(num[1]&num[2]);
	}else if(m==n){
		ans=num[1];
		for(int i=2;i<=n;i++){
			ans=ans&num[i];
		}
	}
	return 0;
}
