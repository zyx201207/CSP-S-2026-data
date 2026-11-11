#include<bits/stdc++.h>
#define int long long
using namespace std;
//Oct31==Dec25?
const int N=500010;
/*
5 5
1 2 4 8 9 
*/ 
/*
6 8
-3 -1 2 2 2 7
*/
int n,lst[N];
long long m,a[N];
bool check(int x){
	unsigned long long ans=0;
	int cnt=0;
	for(int i=lst[x];i>=1;i--){
		cnt++;
		ans+=(a[lst[x]]-a[i]);
		if(cnt==x){
			return ans<=m;
		}
	}
	return ans<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		//cout<<a[i]<<" ";
		if(i==n) lst[i]=n;
		else if(a[i]==a[i+1]) lst[i]=lst[i+1];
		else lst[i]=i;
	}
	//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
		//cout<<a[mid]<<endl;
	}
	//cout<<cnt<<endl;
	cout<<l<<endl;
	return 0;
} 
