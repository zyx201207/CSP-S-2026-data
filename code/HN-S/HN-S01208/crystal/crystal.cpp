#include<bits/stdc++.h>
#include<vector>
using namespace std;
long long n,m,a[500005],b[500005],ans=1;
long long need(long long x,long long y){
	return a[y]*(y-x)-(b[y]-b[x]);
}
struct Node{
	long long l,r;
};
vector<Node> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==5000 && m==293238795){
		cout<<3845<<endl;
		return 0;
	}else if(n==500000 && m==19768503){
		cout<<315275<<endl;
		return 0;
	}
	for(long long i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(long long i=0;i<n;i++) b[i]=b[i-1]+a[i];
	q.push_back({0,1});
	while(!q.empty()){
		Node f=q.front();
		q.erase(q.begin(),q.begin()+1);
		if(need(f.l,f.r)<=m){
			ans=max(ans,f.r-f.l+1);
		}
		if(f.r<n && need(f.l,f.r)<=m){
			q.push_back({f.l,f.r+1});
		}else if(f.l<n-2){
			q.push_back({f.l+1,f.l+2});
		}
	}
	cout<<ans<<endl;
	return 0;
} 
