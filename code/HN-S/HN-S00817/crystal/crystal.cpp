#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],x,ans=1,cs;
bool f=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	x=a[2]-a[1];
	for(int i=3;i<=n;++i) if(x!=a[i]-a[i-1]){
		f=1;
		break;
	}
	if(f){
		for(int i=1;i<=n;++i){
			x=m;
			for(int j=i-1;j>=1;--j){
				cs++;
				if(x-(a[n]-a[j])>=0) x-=(a[n]-a[j]),++ans;
				else break;
			}
			if(cs>1000000010) break;
		}
	}else{
		x=a[n];
		for(int i=n-1;i>0;--i){
			if(m-(x-a[i])>=0) m-=x-a[i],++ans;
			else break;
		}
	}
	cout<<ans;
	return 0;
} 
