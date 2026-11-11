#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N],s[N],c[N];
bool check(int x,int now){
	if(s[now]-s[x]-(c[now+1]-c[x+1])*x<=m)return 1;
	return 0;
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("wa.out","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	sort(c+1,c+n+1);
	for(int i=1;i<n;i++){
		a[i]=c[i+1]-c[i];
		s[i]=a[i]*i+s[i-1];
//		cout<<s[i]<<" ";
	}
//	cout<<"\n";
	for(int i=1;i<n;i++){
		int l=0,r=i,res=i;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i))res=mid,r=mid-1;
			else l=mid+1;
		}
//		cout<<i<<" "<<res<<" "<<s[i]-s[res]-(c[i+1]-c[res+1])*res<<"\n";
		ans=max(i-res,ans);
	}
	cout<<ans+1;
	return 0;
}
//5 5
//1 2 4 8 9
//5 8
//-3 -1 2 2 7
//Oct31==Dec25?
