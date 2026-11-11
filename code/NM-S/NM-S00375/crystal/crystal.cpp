#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1;
const int N=1e8;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int cnt=n/2+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=cnt-1,j=cnt+1;i>=0&&j<=n+1;){
		if(m<=0) break;
		if(abs(a[j]-a[cnt])<=abs(a[cnt]-a[i])){
			j++;
			ans++;
		}
		else if(abs(a[j]-a[cnt])>abs(a[cnt]-a[i])){
			i--;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
