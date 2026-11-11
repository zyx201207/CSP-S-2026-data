#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,b,c,t,v,ans=1;
	cin>>n>>m;
	long long a[100005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans=a[1]+a[2];
		if(ans<0){
			ans+=m;
		}
    }
	cout<<ans;
    return 0;
}
