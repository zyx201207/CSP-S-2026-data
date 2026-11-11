#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],yusum=1;
long long num=pow(2,31)-1;
long long maxans=0;
bool xa=1;
vector<int> v;
void dfs(long long index,long long cnt){
	if(cnt>m){
		return;
	}
	if(index>n){
		if(cnt!=m){
			return;
		}
		long long ans=1;
		for(int i=0;i<v.size();i++){
			ans=(ans&a[v[i]]);
		}
		maxans=max(maxans,ans);
	}
	v.push_back(index);
	dfs(index+1,cnt+1);
	v.pop_back();
	dfs(index+1,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		yusum=(yusum&a[i]);
		if((a[i]&num)!=a[i]){
			xa=0;
		}
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		cout<<yusum;
		return 0;
	}
	if(xa){
		cout<<a[n-m+1];
		return 0;
	}
	dfs(1,0);
	cout<<maxans;
	return 0;
} 
