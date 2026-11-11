#include<bits/stdc++.h>
using namespace std;
vector<int> a[4010];
bool p[4010];
/*
int f(int x){
	int m;
	vector<int> q;
	int mx=0;
	q.push_back(x);
	
	q.push_back(x);
	int k=0;
	while(q.size()!=n){
		for(int i=0;i<a[q[k]].size();i++){
			if(p[a[q[k]][i]]==0){
				q.push_back(a[q[k]][i]);
				mx=max(mx,q[k])	
			}
		}
		k++;
	}
}
*/
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,k;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		int j=0;
		while(k<=n){
			k*=2;
			j++;
		}
		cout<<i-1<<"\n";
	}
	return 0;
}
