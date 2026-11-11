#include <bits/stdc++.h>
using namespace std;
long long a[10086];
long long vis[1086]={0},bigvis[10086];
queue<long long> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n,m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=i;i<n;j++){
			if(vis[a[j]]!=0){
				for(long long k=0;k<static_cast<long long>(q.size());k++){
					vis[q.front()]=0;
					q.pop();
				}
			}
			q.push(a[j]);
			vis[a[j]]++;
		}
		for(long long j=0;j<n;j++){
			if(vis[j]){
				bigvis[j]=vis[j];
				vis[j]=0;
			}
		}
		
	}
	for(long long i=0;i<m;i++){
		cout<<bigvis[i];
	}
	return 0;
}
