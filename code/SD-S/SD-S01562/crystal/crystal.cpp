#include<bits/stdc++.h>
using namespace std;

namespace smilemask{
	#define rd read()
	typedef long long ll;
	inline ll read(){
		ll num=0,sign=1;char ch=getchar();
		while(!isdigit(ch)){
			if(ch=='-') sign=-1;
			ch=getchar();
		}while(isdigit(ch)){
			num=(num<<1)+(num<<3)+ch-'0';
			ch=getchar();
		}return num*sign;
	}
	
	const int N=5e5+10;
	
	int n;
	ll a[N],s[N],m;

	void Main(){
		n=rd,m=rd;
		for(int i=1;i<=n;i++)
			a[i]=rd;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i];
		int ans=1;
		for(int i=1;i<=n;i++){
			int l=1,r=i,res=i;
			while(l<=r){
				int mid=(l+r)>>1;
				ll cost=(i-mid+1)*a[i]-(s[i]-s[mid-1]);
				if(cost<=m) r=mid-1,res=mid;
				else l=mid+1;
			}
			ans=max(ans,i-res+1);
		}
		cout<<ans<<endl;
	}
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	smilemask::Main();
	return 0;
}

