#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,k;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}//O(n)
	sort(a+1,a+n+1,cmp);
	long long s=a[1];
	for(int i=2;i<=k;i++){
		s=s&a[i];
	}
	cout<<s<<'\n';
	return 0;
} 
