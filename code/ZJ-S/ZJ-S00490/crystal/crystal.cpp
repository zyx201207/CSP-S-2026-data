#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,ans=1,num=1;
ll m,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ans=-1;
		for(int j=i-num;j>=1;j--){
			ll k=a[i]*(i-j+1)-b[i]+b[j-1];
			if(k<=m) ans=i-j+1;
			else break;
		}
		num=max(num,ans);
	}
	cout<<num;
	
	return 0;
}
