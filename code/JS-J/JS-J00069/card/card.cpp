#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define db double 




int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	vector<int> ct1(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		
	vector<int> ct(m+1,0);
	vector<int> v(m+1,0);
	queue<int> q;
		for(int j=i;j<=n;j++){
			if(v[j]){
				while(q.front() != j){
					v[q.front()]=0;
					ct[q.front()]=0;
					q.pop();
				}
				v[q.front()]=0;
				ct[q.front()]=0;
				q.pop();
			}
			q.push(j);
			v[j]=1;
			ct[j]++;
		}
		for(int j=1;j<=m;j++){
			ct1[j]+=ct[j];
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ct1[i]<<" ";
	}
	
	
	
	
	
	return 0;
}

