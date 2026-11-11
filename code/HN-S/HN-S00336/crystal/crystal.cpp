#include<bits/stdc++.h>//17min«–µÙ£°π¿∑÷100pts 
#define int long long
using namespace std;
inline int read(){
	int x(0),sign(1);
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()){
		if(ch=='-'){
			sign=-1;
		}
	}
	for(;isdigit(ch);ch=getchar()){
		x=x*10+ch-'0';
	}
	return x*sign;
}
int n,m;
int a[500005];
int chf[500005];
queue<int>q;
int ans;
__int128 sum;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;++i){
		chf[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;++i){
		sum+=q.size()*chf[i];
		q.push(a[i]);
		while(!q.empty()){
			if(sum>m){
				sum-=(a[i]-q.front());
				q.pop();
			}else{
				break;
			}
		}
		int sz=q.size();
		ans=max(ans,sz);
	}
	printf("%lld",ans);
	return 0;
}
