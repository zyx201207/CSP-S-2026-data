#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n,m;
ll a[N],sum;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	sum=a[1]&a[2];
	for(int i=2;i<=m-1;i++){
		sum=sum&a[i+1];
	}
	cout<<sum;
	return 0;
}