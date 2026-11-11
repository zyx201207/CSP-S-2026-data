#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,a[500005],ans=0,sum=0,pre[500005],tot=0;
priority_queue<int,vector<int>,greater<int> >pq;
vector<int>v;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		tot+=a[i];
		sum=a[i]*(pq.size()+1)-tot;
		if(sum>m){
			while(!pq.empty()&&(sum>m)){
				int f=pq.top();
				pq.pop();
				tot-=a[i];
				tot-=f;
				if(pq.empty())sum=0; 
				else sum=pq.top()*pq.size()-tot;
			}
		}
		else pq.push(a[i]);
		ans=max(ans,(int)pq.size());
//		cout<<"pq.size="<<pq.size()<<endl;
//		cout<<"tot="<<tot<<endl;
//		cout<<"sum="<<sum<<endl;
	}
	cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
/*
7 3
1 2 10000 10000 20000 20001 20002
*/
