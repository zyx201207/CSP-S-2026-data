#include<bits/stdc++.h>
using namespace std;
const int N = 5e5;
long long n,m;
long long a[N];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	if(n>5000){
		cout<<0;
		return 0;
	} 
	sort(a,a+n,cmp);
	long long max_ans = 0;
	for(int i=0;i<n;i++){
		long long maxn = a[i];
		long long left = m;
		long long cnt = 1;
		for(int j=i+1;j<n;j++){
			if(left >= maxn - a[j]){
				left -= maxn -a[j];
				cnt++;
			}
		}
		if(cnt >= max_ans) max_ans = cnt;
	}
	cout<<max_ans;
	return 0;
}
