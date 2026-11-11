#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
map<int,int>cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		vector<int>q(n,0);
		for(int j=i;j<n;j++){
			for(int k=0;k<q.size();k++)
				if(q[k]==a[j]){
					for(int o=k;o<q.size();o++)q[o]=-1;
					break;
				}
			q.push_back(a[i]);
		}
		for(int j=0;j<q.size();j++){
			if(q[j]!=-1)cnt[q[j]]++;
		}
	}
	for(int j=0;j<n;j++){
		int maxc=0,ii=0;
		for(int i=0;i<n;i++){
			if(maxc<cnt[a[i]]){
				maxc=cnt[a[i]];
				ii=a[i];
			}
		}
		if(maxc<=0)break;
		cout<<maxc<<" ";
		cnt[ii]=-1;
	}
	return 0;
}
