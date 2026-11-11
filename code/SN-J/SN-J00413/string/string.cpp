#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,a[maxn],s[maxn],len;
char c[maxn];
int getid(int x){
	int L=1,R=n,res=0;
	while(L<=R){
		int mid=L+R>>1;
		if(s[mid]>=x){
			res=mid;
			R=mid-1;
		}else L=mid+1;
	}
	return res;
}
string f;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		s[i]=s[i-1]+a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	int l=len/2,r=len/2+2;
	if(len%2==0)l=len/2,r=len/2+1;
	int ans=0;
	while(l>=1){
		int idl=getid(l),idr=getid(r);
		if(l-s[idl-1]>=s[idr]-r+1){
			if(c[idl]!=c[idr])ans+=s[idr]-r+1;
			l-=s[idr]-r+1;
			r=s[idr]+1;
		}else{
			if(c[idl]!=c[idr])ans+=l-s[idl-1];
			r+=l-s[idl-1];
			l=s[idl-1];
		}
	}
	cout<<ans;
	return 0;
}
/*
9:25
我应该是最慢的一个了，笔误卡了好久。
太费事懒得线性了，应该能过 
*/
