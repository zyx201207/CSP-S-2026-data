#include <bits/stdc++.h>
using namespace std;
long long read(){
	long long ans = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ans = ans*10+ch-'0';
		ch = getchar();
	}
	return ans*f;
}
const int N = 5e5 + 10;
long long n,m,sum,ans=INT_MIN;
long long a[N],diff[N];


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read(),m = read();
	for(int i=1;i<=n;i++){
		a[i] = read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		diff[i] = abs(a[i]-a[i-1]);
	}
	long long head=1,tail=1;
	sum = diff[1] = 0;
	while(head<=tail&&tail<=n){
		if(sum<=m){
			tail++;
			sum += diff[tail]*(tail-head);
		}
		if(sum>m){
			sum -= diff[tail]+diff[head];
			head++;
		}
		if(sum<=m) ans = max(ans,tail-head+1);
	}
	ans = max(ans,1ll);
	cout<<ans;
	
	
	return 0;
}
/*
5 5
1 2 4 8 9
1 1
2 1
3 2
4 4
5 1

2 2
3 4
4 8
4 7
4 6
4 4
4 5
4 1
4 1
4



*/
