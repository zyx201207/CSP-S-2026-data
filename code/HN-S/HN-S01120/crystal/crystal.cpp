#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,M=1e18;
int n,m,a[N],ans=1;
bool B=1,A=1;
int f(int x,int id){
	priority_queue<int>q;
	int sum=0,num=0;
	for(int i=1;i<=n;i++){
		if(i==id)continue;
		int t=max(a[i],x)-min(a[i],x);
		q.push(t);
		sum+=t;num++;
		if(sum>m){
			num--;
			sum-=q.top();
			q.pop();
		}
	}
	return num;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int t=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(a[i]!=i)A=0;
		if(i!=1&&a[i]-a[i-1]!=t)B=0;		
	}
	if(A||B){
		if(m<t)cout<<1;
		else if(m==t)cout<<2;
		else{
			sort(a+1,a+n+1);
			priority_queue<int>q;
			int sum=0,f=0;
			for(int i=1;i<=n;i++){
				q.push(a[n]-a[i]);
				sum+=(a[n]-a[i]);
				if(sum>m){
					sum-=q.top();
					q.pop();
				}
			}
			cout<<q.size();
		}
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		ans=max(ans,f(a[i],i));
	cout<<ans+1;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
