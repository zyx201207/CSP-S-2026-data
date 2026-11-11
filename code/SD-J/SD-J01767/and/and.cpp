#include<bits/stdc++.h>
using namespace std;
#define N 200005
long long n,m,ans=-1,num;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		num=a[i];
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}
