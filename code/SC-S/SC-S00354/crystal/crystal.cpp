#include<bits/stdc++.h>
#include<stdio.h>
#include<cstdio>
using namespace std;
const int N=5e5+5;
int n,a[N];
long long m,ans=0;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int st=time(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int xx=n/2;
	for(;xx<=n&&xx>=1;){
		long long mart=0;
		int z=m;
		for(int i=1;i<=n;i++){
			q.push({a[i]-a[xx],i});
		}
		while(!q.empty()){
			int val=q.top().first;
			q.pop();
			if(val<=z&&val<=0){
				z+=val;
				mart++;
			} 
		}
		int en=time(0);
		//cout<<en<<' ';
		if(en-st>1)break;
		//cout<<xx<<' ';
		ans=max(mart,ans);
		if(xx==n/2)xx++;
		else if(xx>1.0*n/2)xx=n-xx-1;
		else if(xx<1.0*n/2)xx=n-xx;
	}
	cout<<max(ans,(long long)1);
	return 0;
} 