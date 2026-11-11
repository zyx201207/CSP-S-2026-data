#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;

int n;
long long m,tot;
long long a[N];

long long ans;

queue<long long> q;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	
	sort(a+1,a+1+n);
	
	q.push(a[1]);
	ans=1;
	tot=a[1];
	for(int i=2;i<=n;i++){
		long long c=q.size()*a[i]-tot;
		if(c<=m){
			q.push(a[i]);
			tot+=a[i];
		}
		else{
			while(q.size()&&q.size()*a[i]-tot>m){
				tot-=q.front();
				q.pop();
			}
			q.push(a[i]);
			tot+=a[i];
		}
		long long len=q.size();
		ans=max(ans,len);
	}
	
	cout<<ans;
	
	return 0;
}