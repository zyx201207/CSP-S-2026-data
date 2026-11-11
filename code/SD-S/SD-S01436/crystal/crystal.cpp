#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long m,ans=0,dj=0;
	cin>>n>>m;
	deque<long long>dq;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dq.push_back(a[1]);
	for(int i=2;i<=n;i++){
		long long b=dq.back();
		long long num=dq.size();
		long long ddj=(a[i]-b)*num;
		if(dj+ddj<=m){
			dq.push_back(a[i]);
			dj+=ddj;
			ans=max(ans,(long long)dq.size());
		}else{
			dj+=ddj;
			dq.push_back(a[i]);
			while(dj>m){
				if(dj<=m){
					break;
				}
				dj-=(long long)(a[i]-dq.front());
				dq.pop_front();
			}
			ans=max(ans,(long long)dq.size());
		}
	}
	cout<<ans;
	return 0;
} 
