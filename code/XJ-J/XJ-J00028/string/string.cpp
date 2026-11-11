#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+100;
int n;
struct aaa{
	int sum;string x;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].x;
	}
	int l=1,r=n;
	int res=0;
	while(l<r){
		string p1=a[l].x,p2=a[r].x;
		int mi=min(a[l].sum,a[r].sum);
		if(p1==p2){
			a[l].sum-=mi,a[r].sum-=mi;
			if(a[l].sum==0) l++;
			if(a[r].sum==0) r--;
		}else if(p1!=p2){
			a[l].sum-=mi,a[r].sum-=mi;
			if(a[l].sum==0) l++;
			if(a[r].sum==0) r--;
			res+=mi;
		}
	}
	cout<<res;
	return 0;
}
