#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0,dp[500005]={0},sum=1,t=0,cnt=1;
long long a[500005]={0},b=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		t=m;
		cnt=1;
		for(int j=i-1;j>0;j--){
			b=a[i]-a[j];
			if(t-b>=0 || b==0){
				t-=b;
				cnt++;
			}
			else break;
		}
		sum=max(sum,cnt);
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
