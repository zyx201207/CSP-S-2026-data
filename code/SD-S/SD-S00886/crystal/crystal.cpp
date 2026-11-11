#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int j=i,sum=0;
		while(sum+a[i]-a[j]<=m&&j>=1){
			sum=sum+a[i]-a[j];
			j--;
		}
		ans=max(ans,i-j);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
