#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;

const int MAXN=1e6+5;
int a[MAXN];
bool check(int*a,int n){
	int b=a[0];
	for(int i=0;i<n;i++){
		if(a[i]!=b)return false;
	}return true;
}
signed main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(check(a,n)){cout<<n;return 0;}
	sort(a,a+n);int cnt=m;
	for(int i=0;i<n-2;i++){
		a[i]+=cnt;cnt=a[i]-a[i+1];
		a[i]-=cnt/2;a[i+1]+=cnt/2;
	}
	int l=a[0],ans=0;
	for(int i:a)if(i==l)ans++;
	cout<<ans;
	return 0;
}
