#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N=1111110;
int a[N];
int ans[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=n;++i){
		int x=a[i];
		while(x){
			if(a[i]%2==1) a[i]=a[i]*10+1;
			else a[i]=a[i]*10;
			a[i]/2;
		}
	}
	for(int i=2;i<n;++i){
		int w=10;
		int ll=a[i]%w;
		int zz=a[i-1]%w;
		if(ll==2) ll=a[i]%(w*10)+1;
		if(ll==1&&zz==1){
			ans[i]=ans[i]*10;
			ll=a[i]%(w*10)+1;
		}
		else if(ll==1&&zz==0||ll==0&&zz==1) ans[i]=ans[i]*10+1;
		else ans[i]=ans[i]*10;
		w*=10;
	}
		for(int i=1;i<=n;++i){
			while(ans[i]){
			    int sum=1;
		    	int of=(ans[i]%10)^sum;
		    	sum++;
		    	ans[i]/10;	
			}
		}
		sort(ans+1,ans+n+1);
		cout<<ans[n];
	return 0;
}