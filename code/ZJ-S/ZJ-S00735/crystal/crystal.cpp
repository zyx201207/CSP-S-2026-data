#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int d=a[i]-a[i-1];
		if(m>=d*(i-1)){
			m-=d*(i-1);
			ans++;
		}
		else{
			break;
		}
	}
	cout<<ans;
	return 0;
}