#include<bits/stdc++.h>
using namespace std;
long long m,n,num,sum,ans;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==0){
		for(int i=2;i<=n;i++){
			if(a[i-1]==a[i]) sum++;
			num=max(num,sum);
		}
		cout<<num;
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			num=a[i]-a[j];
			if(num<=m){
				ans++;
				m-=num;
			}
		}
		ans=max(ans,sum);
		sum=ans;
	}
	cout<<ans;
	return 0;
}
