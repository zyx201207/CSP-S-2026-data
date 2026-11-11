#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool flag1=true,flag2=true;
	for(int i=1;i<=n;i++){
		if(i>=2&&a[i]!=a[i-1]) flag1=false;
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flag2=false;
	}
	if(flag1==true){
		cout<<n;
		return 0;
	}
	if(flag2==true){
		cout<<m/(a[2]-a[1])+1;
		return 0;
	}
	long long sum=0,tmp=1;
	for(int i=2;i<=n;i++){
		sum+=(a[i]-a[i-1])*tmp;
		if(sum>m) break;
		tmp++;
	}
	cout<<tmp;
	return 0;
}
