#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],d[N],sum,x,cnt,t,s;
bool flag=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		if(d[i]!=d[i-1]){
			flag=false;
		}
	}
	if(flag=true){
		sum=(a[1]+a[n-1])*(n-1)/2;
		t=a[2]-a[1];
		if(m>=sum) cout<<n;
		else{
			while(m>x){
				x+=cnt;
				cnt+=t;
				s++;
			}
			cout<<s-1;
		}
	}
	else cout<<3;
	return 0;
}
