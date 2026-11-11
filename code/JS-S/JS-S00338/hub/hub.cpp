#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],ans=1;
unsigned long long m;
queue <long long> q;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","r",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long mony=m,cost=0;
	for(int i=1;i<=n;i++){
		cost=i*(a[i+1]-a[i]);
		if(cost>mony){
			long long x=q.front();
			if((i-1)*(a[i+1]-a[i])<=a[i]-a[x]){
				q.pop();
				cost+=a[i]-a[x];
			}else{
				break;
			}
		}else{
			mony-=cost;
			ans++;
		}
		q.push(i);
	}
	if(n==1)cout<<1;
	else cout<<ans;
	return 0;
}
