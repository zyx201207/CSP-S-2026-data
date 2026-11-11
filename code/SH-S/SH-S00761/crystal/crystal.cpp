//1 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500500],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(ans=1;m>=0&&ans<n;ans++){
		m-=(a[ans]-a[ans-1])*(ans);
	}
	cout<<ans-1<<endl;
	return 0;
}
