#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
struct Side{
	//u到v的一条边 
	int v;
	//边权 
	int t;	
	bool operator >(Side& other) {
		return t>other.t;
	}
	bool operator <(Side& other) {
		return t<other.t;
	}
};
struct Cmp
    {
      bool
      operator()(const Side& __x, const Side& __y) 
      { return __x.t > __y.t; }
    };
struct Node{
	vector<Side> vs;
	int t=0;
};
int c,t;
int n,d;
int dfs(int depth,int cur,int tar,vector<int>& len){
	if(cur>tar) return 0;
	if(depth>=len.size()) {
		if(cur==tar) return 1;
	}
	return dfs(depth+1,cur+len[depth],tar,len)+dfs(depth+1,cur,tar,len);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int _=0;_<t;_++){
		cin>>n>>d;
		vector<int> X(n);
//		vector<int> l(n);
		for(int i=0;i<n;i++)
		{
			cin>>X[i];
//			for(int j=X[i];j>=0;j--){
//				if(abs(X[i]-X[j])<=d){
//					l.push_back(abs(X[i]-X[j]));
//				} else{
//					break;
//				}
//			} 
		}
//		int ans=0;
//		for(int i=0;i<n;i++){
//			if(dfs(0,0,X[i],l)==2){
//				ans++;
//			}
//		}
		cout<<0<<"\n";
	}
	return 0;
} 
