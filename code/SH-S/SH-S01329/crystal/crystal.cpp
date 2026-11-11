#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5;

long long n,m;
long long cry[M];
long long pre[M];
long long stp;
long long ans;

void logic(){
	long long curm = 1;
	long long maxn = -1,tmp = 0;
	for(int i = n;i >= 1;i--){
		tmp = pre[i] - pre[curm - 1] - (stp - cry[i]) * i;
		if(tmp == m){
			maxn = max(maxn,i - curm + 1);
		}
		else{
			long long l = 1,r = i;
			long long mid = l + ((r - l) / 2);
			long long tmp2 = 0;
			while(l <= r){
				mid = l + ((r - l) / 2);
				tmp2 = pre[i] - pre[mid - 1] - (stp - cry[i]) * (i - mid + 1);
				if(tmp2 <= m){
					maxn = max(maxn,i - mid + 1);
					r = mid - 1;
				}
				else if(tmp2 > m){
					l = mid + 1;
				}
			}
		}

	}
	
	
	ans = maxn;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>cry[i];
	}
	
	sort(cry + 1,cry + 1 + n);
	
	stp = cry[n];
	
	for(int i = 1;i <= n;i++){
		pre[i] = pre[i - 1] + stp - cry[i];
	}
	
	logic();
	
	cout<<ans;
	return 0;
}

