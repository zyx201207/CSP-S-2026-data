#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=2;i<=n;i++){
    	long long b[500010],sum=m,ans1=0;
    	for(int j=1;j<=i;j++){
    		b[j]=a[i]-a[j];
		}
		sort(b+1,b+i+1);
		for(int j=1;j<=i;j++){
			if(sum>b[i]){
				sum-=b[i];
				ans1++;
			}
			else{
				break;
			}
		}
		if(ans1>ans){
			ans=ans1;
		}
	}
	cout<<ans;
	return 0;
}