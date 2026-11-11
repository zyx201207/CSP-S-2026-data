#include<bits/stdc++.h>
using namespace std;
long long  a[500006];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	bool flag=0;
	long long  u=0;
	priority_queue<long long >q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		if(a[i]==i){
			flag=1;
		}
		q.push(a[i]);
	}
	u=q.top();
	int now=q.top();
	q.pop();
	int l2=q.top();
	u-=q.top();
	q.push(now);
	if(n>5000){
		if(flag==1){
			cout<<m;
			return 0;
		}
		else {
			int o=0;
			int i=1;
			int j=m/u;
			while(1){
				if(j-i>=0){
					j-=i;
					i++;
					o++;
				}
				else{
					break;
				}
			}
			cout<<o+1;
			return 0;     

		}
	}
	for(int i=1;i<=n;i++){
		a[i]=q.top();
		q.pop();
	}
	long long  ans=0;
	long long maxn=-1e18;
	for(int i=1;i<=n;i++){
		long long x=m;
		ans=0;
		int md=a[i];
		for(int j=i;j<=n;j++){
			
			if(x-(md-a[j])>0){
				x=x-(md-a[j]);
				ans++;
			}
			else if(x-(md-a[j])==0){
				x=x-(md-a[j]);
				ans++;
				break;
			}
			else{
				break;
			}
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
