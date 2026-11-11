#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[50050],ca[50050],sum,ans=-1 ;//sum表示前缀和 
void cafen(){
	for(ll i=1;i<=n;i++){//差分数组，1号差分数组存储1与0之间的差分 
		ca[i]=a[i]-a[i-1];
	}
}
void solve(ll num){
	sum=0;
	for(ll i=num;i<=n;i++){
		sum+=(i-num)*ca[i];
		if(sum>m and ans<i-num-1){
			ans=i-num;
			break;
		} 
		else if(sum==m and ans<i-num and ca[i+1]!=0){
			ans=i-num+1;
			break;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cafen();
	for(ll i=1;i<=n;i++) solve(i);
	cout<<ans<<endl;
	return 0;
}
