#include<iostream>
#include<algorithm>
using namespace std;
const int N=3e5+20;
long long n,m,a[N],ans;
//bool cmp(long long a,long long b){
//	return a>b;
//}
long long csm(int a,int b){
	int ans=1;
	while(b>0){
		if(b&1){
			ans=ans*a;
		}
		a*=a;
		b>>=1;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=csm(2,30)-1;
//	cout<<ans;
	sort(a+1,a+1+n);
	for (int i=n;i>=n-m+1;i--){
		ans=a[i]&ans;
	}
	cout<<ans;
	return 0;
} 
