#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
const int N=200005;
long long a[N];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,cmp);
	cnt=a[0];
	for(int i=1;i<m;i++){
		cnt&=a[i];
	}
	cout<<cnt;
	return 0;
}
