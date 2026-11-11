#include<bits/stdc++.h> 
using namespace std;
long long n,m,ans=0,ans1=0;
bool book=1;
bool cmp(long long a,long long b){
	return a>b; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	vector<long long> a(n),vis(n,-1);
	for(int i=0;i<n;i++) 
	   cin>>a[i];
	sort(a.begin(),a.end(),cmp);
	ans=a[0];
	for(int i=1;i<m;i++)
	    ans=ans&a[i];
	int l=m;
	for(int i=0;i<n;i++){
		if(a[i]%2==0 and book){
		   ans1=a[i],m--;
		   book=0;
		   vis[i]=1;
		}
		else if(a[i]%2==0)
		   ans1&=a[i],m--,vis[i]=1;
	}
	for(int i=0;i<l and m>=0;i++)
	    if(vis[i]==-1)
	       ans1&=a[i];
	cout<<max(ans,ans1);
	return 0;
}
