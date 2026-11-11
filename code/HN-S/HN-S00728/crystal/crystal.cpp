#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=5e5+5;
long long n,m,k;
long long a[N]; 
long long ans; 
bool f=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	rep(i,1,n){
		cin>>a[i];
		if(i>2&&(a[i]-a[i-1]!=a[i-1]-a[i-2]))f=0;
	}
	sort(a+1,a+n+1);
	if(!f){
		rep(i,1,n){
		long long lm=m;
		long long res=1;
		for(int j=i-1;j>=1;j--){
			if(lm>=a[i]-a[j]){
				lm-=(a[i]-a[j]);
				res++;
			}else break;
		}
		ans=max(ans,res);
	}
	}else {
		int p=m/(a[2]-a[1]);
		int res=0;
		rep(i,1,n){
			res+=i;
			if(res+i+1>p){
				ans=i+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
//75+100+8+10=192
