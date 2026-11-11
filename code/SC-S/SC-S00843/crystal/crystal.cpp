#include<bits/stdc++.h>
using namespace std;
int const N=5e5+1;
long long a[N],sum[N];
long long m;
int n,ans=-1;
long long read(){
	char ch=getchar();
	long long res=0;
	int f=1;
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void print(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		print(x/10);
	}
	putchar((x%10)^48);
}
int work(int id){//在不超过 m 次操作情况下，能凑出多少个 a[id]
	int l=1,r=id-1,mid,res=id-1;//res：最多可以操作 [res, id-1]
	while(l<=r){
		mid=(l+r)>>1;
		if(sum[id-1]-sum[mid-1]+m>=(id-mid)*a[id]){
			res=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
//	cout<<id<<" : ["<<res<<' '<<id-1<<"]"<<'\n';
	return id-res+1;//别忘了加上 id 本身
}
void solve(){
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;++i){
		if(i<n&&a[i+1]==a[i]){//重复元素只算最后一个就行了
			continue;
		}
		ans=max(ans,work(i));
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	solve();
	print(ans);
	return 0;
}
/*

Input #1:

5 5
1 2 4 8 9

Output #1:

3

Input #2:

5 8
-3 -1 2 2 7

Output #2:

4

*/