//CSP×îºóÒ»Îè 
#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
priority_queue<pair<long long,int> >q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)q.push({a[i],i});
	long long ans=0,res=0;
	for(int i=n;i>=1;i--){
		while(!q.empty()){
			while(!q.empty()&&q.top().second>i)q.pop();
			if(q.empty())break; 
			long long u=q.top().first;
			if(m>=a[i]-u)m=m-(a[i]-u),res++;
			else break;
			q.pop(); 
		}
		ans=max(res,ans);
		m+=(a[i]-a[i-1])*(res-1);
		res--;
	}
	cout<<ans;
	return 0;
} 
