#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<node> a;
	long long sum=0;
	for(int i=1;i<=n;i++){
		long long y;
		char C;
		cin>>y>>C;
		if(a.size()&&C==a[a.size()-1].c){
			a[a.size()-1].x+=y;
		}else{
			a.push_back({y,C});
		}
		sum+=y;                       
	}
	long long ans=0,l=0,r=a.size()-1;
	while(sum>0){
		long long cur=min(a[l].x,a[r].x);
		if(a[l].c!=a[r].c){
			ans+=cur;
		}
		sum-=cur*2LL;
		if(a[l].x>a[r].x){
			a[l].x-=cur;
			r--;
		}else if(a[l].x<a[r].x){
			a[r].x-=cur;
			l++;
		}else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
