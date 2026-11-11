#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans;
bool flag1=true;
long long a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	cin>>n>>m;
	ans=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2){
			if(a[i]!=a[i-1])flag1=false;
		}
	}
	if(flag1){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		long long t=m;int j=i-1;long long ans1=1;
		while(t>0&&j>0){
			int s=a[i]-a[j];
			if(t-s<0)break;
			t-=s;
			j--;
			ans1++;
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}
