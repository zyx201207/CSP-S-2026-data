#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005]={},cha[5000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crytal.in","r",stdin);
	freopen("crytal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cha[i]=a[i+1]-a[i];
	}
	long long ans=0;
	for(int i=n;i>1;i--){
		long long m1=m,sum=1;
		for(int j=i-1;j>0;j--){
			int c=a[i]-a[j];
			if(c<=m1){
				m1-=c;
				sum++;
			}
			if(sum<=0)break;
		} 
		ans=max(ans,sum);
	}
	cout<<ans;
	fclose(stdin);
	return 0;
}
