#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,a[N],m,ans=1,b[N];
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	long long head=1,k=0;
	for(int i=1;i<=n;i++){
		while(a[i]*(i-head+1)-(b[i]-b[head-1])>m){
			head++;
		}
		ans=max(ans,i-head+1);	
	}
	cout<<ans;
	return 0;
}