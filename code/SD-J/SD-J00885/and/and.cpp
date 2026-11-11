#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
long long n,m;
long long a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m == 1){
		cout<<a[1];
		return 0;
	}
	if(m == n){
		cout<<a[n];
		return 0;
	}
	if(m == 2){
		cout<<a[2];
		return 0;
	}
	if(m == n-1){
		cout<<a[n-1];
	}
	cout<<a[m];
	return 0;
} 
