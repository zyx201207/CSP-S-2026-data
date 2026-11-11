#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,mx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		s[i]=s[i+1]+a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++){
		long long t=m,cnt=0;
		for(int j=i;j>=0;j--){
			if(t-(s[j]-s[i])<0){
				break;
			}
			t-=(s[j]-s[i]);
			cnt++;
		}
		mx=max(mx,cnt);
	}
	cout<<mx;
}
