#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
long long n,p;
bool cmp(int x,int y){
	return x>y; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[p];
	return 0;
}
