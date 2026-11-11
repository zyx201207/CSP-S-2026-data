#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(long long p=1;p<=t;p++){
		long long n,d;
		cin>>n>>d;
		long long dao[n+1],lu[n+1];
		for(long long i=0;i<n;i++) cin>>dao[i];
		queue<int> q;
		q.push(0);
		while(!q.empty()){
			long long dq;
			dq=q.front();
			q.pop();
			for(long long i=dq;i<=n;i++){
				if(dao[i]-dao[dq]>d || lu[i]>0) continue;
				lu[i]=lu[dq]+1;
				q.push(i);
			}
		}
		cout<<0;
	}
	return 0;
}
