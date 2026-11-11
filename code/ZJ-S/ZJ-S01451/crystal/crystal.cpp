#include<bits/stdc++.h>
using namespace std;
#define int long long
#define isd(c) (c>=48 && c<=58)
const int N=5e5+10;
int n,m;
int a[N];
int l,r;
int sum;
int ans;
inline int rd(){
	int f=1,x=0;
	char c;
	for(c=getchar();!isd(c);c=getchar()){
		if(c=='-') f=-1;
	}
	for(;isd(c);c=getchar()){
		x=(x<<3)+(x<<1)+(c-48);
	}
	return x*f;
}
signed main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=rd();m=rd();
	if(n==1){
		cout<<1<<'\n';
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		a[i]=rd();
	}
	sort(a+1,a+1+n);
	l=n-1;
	r=n;
	sum=ans=0;
	while(l>=1){
		sum+=a[r]-a[l];
		if(sum<=m){
			ans=max(ans,r-l+1);
		}else{
			while(sum>m){
				sum-=(r-l)*(a[r]-a[r-1]);
				r--;
			}
		}
		l--;
	}
	ans=max(ans,r);
	cout<<ans<<'\n';
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
