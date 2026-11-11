#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int a[500005];
template<class T>
inline void read(T &a){
	a=0;char ch=getchar();int f=1;
	while(ch < '0' || ch > '9')f=(ch=='-'?-1:1),ch=getchar();
	while(ch >='0' && ch <='9')a=(a<<3)+(a<<1)+(ch^48),ch=getchar();
	a*=f;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;read(n);read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1);
	int ans=0,sum=0,Ans=0;
	for(int i=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*ans;
		ans++;
		q.push(a[i]);
		while(!q.empty() && sum > m){
			sum-=a[i]-q.top();ans--;
			q.pop();
		}
		Ans=max(Ans,ans);
	}
	cout<<Ans;
}
