#include<bits/stdc++.h>
using namespace std;
const int N=500000+100;
long long a[N];
queue<long long>dq;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long c=0;
	for(long long i=1;i<=n;i++){
		dq.push(i);
		if(i-1>0)c+=(a[i]-a[i-1])*(i-dq.front());
		while(c>m){
			c-=a[i]-a[dq.front()];
			dq.pop();
		}
		ans=max(ans,i-dq.front()+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9


5 8
-3 -1 2 2 7
*/