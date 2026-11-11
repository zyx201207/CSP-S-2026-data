#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long s,a[N];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=m;i<=n;i++){
		if(a[i]<=s){
			break;
		}
		s=a[i-m+1];
		for(int j=i-m+1;j<=i;j++){
			s=s&a[j];
		}
	}
	cout<<s;
	return 0;
}
