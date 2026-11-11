#include<bits/stdc++.h>
using namespace std;
long long n,m,ma=-10000000,mi=10000000,ans=0,fin_ans=0;
long long a[500005],b[500005];
int main(){
	ios::sync_with_stdio();
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(ma<a[i]) ma=a[i];
		if(mi>a[i]) mi=a[i];
	}
	for(int i=0;i<500005;i++) b[i]=100000000;
	sort(a,a+n);
	for(int i=mi;i<=ma;i++){
		ans=0;
		long long mm=m;
		for(int j=0;j<=n;j++){
			if(a[j]>=i)b[j]=a[j]-i;
			if(a[j]<i)b[j]=i-a[j];
		}
		sort(b,b+n);
		for(int j=0;j<n;j++){
			if(mm-b[j]>=0){
				mm-=b[j];
				ans++;
			}else{
				break;
			}
		}
		if(ans>fin_ans) fin_ans=ans;
	}
	cout<<fin_ans;
	return 0;
}