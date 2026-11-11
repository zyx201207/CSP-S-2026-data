#include<bits/stdc++.h>
using namespace std;
long long a[200005],f[200005],ss[200005];
string s[200005];
struct Node{
	long long i,x;
}t[200005];
long long wp(long long x){
	long long h = 1;
	for(long long i = 1;i <= x;i ++) h *= 2;
	return h;
}
bool cmp(Node x,Node y){
	return x.x > y.x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,v,ans;
	cin>>n>>m;
	for(long long i = 1;i <= n;i ++) t[i].i = i;
	for(long long i = 1;i <= n;i ++){
		cin>>a[i];
		v = a[i];
		while(v != 0){
			s[i] += to_string(v%2);
			v /= 2;
		}
		ss[i] = s[i].size();
	}
	for(long long i = 30;i >= 0;i --){
		long long cnt = 0,k = wp(i);
		for(long long j = 1;j <= n;j ++)
			if(ss[j] > i and s[j][i] == '1' and f[j] == 0)
				cnt ++;
		if(cnt >= m){
			for(long long j = 1;j <= n;j ++)
				if(ss[j] > i and f[j] == 0 and s[j][i] == '0')
					f[j] = 1;
			for(long long j = 1;j <= n;j ++)
				if(ss[j] > i and f[j] == 0)
					t[j].x += k;
		}
	}
	sort(t+1,t+n+1,cmp);
	ans = a[t[1].i];
	for(long long i = 2;i <= m;i ++) ans &= a[t[i].i];
	cout<<ans;
	return 0;
}
