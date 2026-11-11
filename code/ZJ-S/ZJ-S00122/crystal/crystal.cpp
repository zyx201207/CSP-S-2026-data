#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c=getchar();
	long long s=0,f=1;
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=(s<<1)+(s<<3)+int(c-'0');
		c=getchar();
	}
	return s*f;
}
long long n,m,a[500005],sm[500005],lef,rig,mid,ans;
bool ck(long long w,long long num){
	return (((a[w]*(num+1))-(sm[w]-sm[w-num-1]))<=m);
}
long long erfen(long long q){
	lef=0;rig=q;
	while(lef+1<rig){
		mid=(lef+rig)>>1;
		if(ck(q,mid)){
			lef=mid;
		}
		else{
			rig=mid;
		}
	}
	return (lef+1);
}
bool cmp(long long A,long long B){
	return A<B;
}
int main(){
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		sm[i]=sm[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,erfen(i));
//		cout<<erfen(i)<<endl;
	}
//	cout<<ck(3,2)<<" ";
	cout<<ans;
	return 0;
}