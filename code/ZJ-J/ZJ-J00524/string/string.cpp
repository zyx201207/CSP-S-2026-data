#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=2e5+5;
int n,m;
ll sum[N];
struct node{
	ll num;
	char ch;
}a[N],b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	freopen("string4.in","r",stdin);
//	freopen("string4.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i].num>>a[i].ch;
	for(int i=2;i<=n+1;++i)
		if(a[i].ch==a[i-1].ch)a[i].num+=a[i-1].num;
		else{
			b[++m].ch=a[i-1].ch;
			b[m].num=a[i-1].num;
		}
	for(int i=1;i<=m;++i)sum[i]=sum[i-1]+b[i].num;
	if(m==1){
		cout<<0<<"\n";
		return 0;
	}
//	for(int i=1;i<=m;++i)cout<<b[i].num<<" "<<b[i].ch<<"\n";
	ll p,same=0,k=(sum[m]+1)/2;
	for(int i=1;i<m;++i){
		if(sum[i]==sum[m]-sum[i])same=1;
		if(sum[i]<=k&&sum[i+1]>=k){
			p=i;
			break;
		}
	}
//	cout<<p<<"\n";
	ll s1=0,s2=0;
	for(int i=1;i<=p;++i)
		if(b[i].ch!=b[m-i+1].ch){
			s1+=b[i].num;
			s2+=b[m-i+1].num;
		}
	ll s=abs((sum[m]-sum[p])-sum[p-1]);
	ll Min=min(s1,s2);
	ll Max=max(s1,s2);
	cout<<min(Min+s,Max);
	return 0;
}
/*
4
5 a
1 b
3 c
1 b
*/