#include<bits/stdc++.h>
using namespace std;
int n;int m;
long long a[500000];
int ans;
int b;
void fors(){
	b=abs(b);
	m/=b;
	int i=1;
	while(m>0||i<ans){
		m-=i;
		if(m>0)i++;
	}
	ans=i;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2)  b=a[2]-a[1];
		else if(i>2){
			if(a[i]-a[i-1]!=b) flag=false;
		}
	}
	if(flag){
		fors();
	}else {
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=m;j>=a[i];j--){
				dp[j]=max(dp[j],dp[j-a[i]]+1);
			}
		}
	}
	ans=dp[m];
	cout<<ans;
	return 0;
}
