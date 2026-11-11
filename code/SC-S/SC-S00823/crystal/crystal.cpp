#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long _1=0;bool _2=0;char _3=getchar();
	while(_3<'0'||_3>'9'){
		if(_3=='-') _2=1;
		_3=getchar();
	}while(_3>='0'&&_3<='9')
		_1=(_1<<3)+(_1<<1)+(_3-48),_3=getchar();
	return (_2?-_1:_1);
}
const int N=5e5+5;
long long a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read(),ans=0;long long m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=0,r=i,res=i;
		while(l<=r){
			int mid=l+r>>1;
			if((a[i]*(i-mid)-s[i]+s[mid])<=m) res=mid,r=mid-1;
			else l=mid+1;
		}ans=max(ans,i-res);
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}