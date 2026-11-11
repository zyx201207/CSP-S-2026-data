#include<bits/stdc++.h>
using namespace std;
#define _ long long
_ a,b,c[500001],d[300001],dp[500010],ans[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b;
	for(_ i=1;i<=a;i++){
		dp[i]=1;
		cin>>c[i];
		d[c[i]]=i;
	}
	for(_ i=1;i<=a;i++){
		if(d[c[i]]==i){
			ans[c[i]]+=dp[i];
			dp[i+1]+=dp[i];
		}
		else{
			dp[d[c[i]]]+=dp[i];
		}
	}
	for(_ i=1;i<=b;i++){
		if(i!=1)cout<<' ';
		cout<<ans[i];
	}
	return 0;
}