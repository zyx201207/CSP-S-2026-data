#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
stack<long long> s;
bool p[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)   cin>>a[i];
	for(long long num=1;num<=n;num++){
		for(long long i=num;i<=n;i++){
			if(p[a[i]]==0){
				p[a[i]]=1;
				s.push(a[i]);
			}
			else   while(s.top()!=a[i])   p[s.top()]=0,s.pop();
		}
		for(long long i=1;i<=m;i++){
			if(p[i]==1)   sum[i]++;
			p[i]=0;
		}
		while(!s.empty())   s.pop();
	}
	for(long long i=1;i<=m;i++)   cout<<sum[i]<<" ";
	return 0;
}