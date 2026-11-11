#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[500007];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	long long sam=m,ans=0;
	for(int i=1;i<=n;i++){
		sam+=arr[i];
		//cout<<",,,,,,,,"<<sam<<",,,,,,"<<i<<endl;
		if(sam/i>=arr[i])ans=i;
		if (sam<arr[i])break;
	}
	cout<<ans;
}
