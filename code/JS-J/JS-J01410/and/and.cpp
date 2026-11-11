#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[2000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		cnt=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			cnt=cnt&a[j];
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
