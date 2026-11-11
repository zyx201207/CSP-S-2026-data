#include<bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long a[200010];
bool cmp(unsigned long long x,unsigned long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++) a[i]&=a[i-1];
	cout<<a[m];
	return 0;
} 
