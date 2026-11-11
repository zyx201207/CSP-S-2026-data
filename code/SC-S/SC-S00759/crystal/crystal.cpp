#include<bits/stdc++.h>
using namespace std;
long long a[100005],sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum=a[i]+m;
		if(a[i]==a[i-1]){
			ans++;
		}
		else {
			a[i]--;
			a[i+1]++;
			ans=ans+0;
		}
	}
	//sum=max(ans,sum);
	cout<<sum-11;
	return 0;
}
//TM的敲着么大声和键盘有仇吗？？？ 