#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,m,ans=0;
int a[N];
bool mycmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,mycmp);
	if(m==1){
		cout<<a[1]<<endl;
		return 0;
	}
	ans=a[1];
	for(int i=1;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
 
