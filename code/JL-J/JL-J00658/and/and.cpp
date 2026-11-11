#include<bits/stdc++.h>
using namespace std;
const int N=2e10+10;
long long n,m,a[N],sum;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	sum=a[0];
	for(int i=1;i<m;i++){
		sum=sum&a[i];
	}
	cout<<sum;
}
