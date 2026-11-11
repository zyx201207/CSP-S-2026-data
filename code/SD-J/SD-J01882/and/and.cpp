#include<bits/stdc++.h> 
using namespace std;
int n,m;
long long a[201000];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1,cmp);
	long long anss=0,l=1;
	while(!anss){
		long long ans=a[l];
		for(int i=l+1;i<=m+1-l;i++){
			ans&=a[i];
		} 
		if(ans>anss){
			anss=ans;
			break;
		}
		l++;
	}
	cout<<anss;
	return 0;
}
