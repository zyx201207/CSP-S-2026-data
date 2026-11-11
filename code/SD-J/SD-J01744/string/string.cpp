#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],c[N],i,j,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		char cr;
		cin>>a[i]>>cr;
		c[i]=cr;
	}
	i=1;
	j=n;
	while(i<j){
		int num=min(a[i],a[j]);
		if(c[i]!=c[j]) ans+=num;
		a[i]-=num;
		a[j]-=num;
		if(a[i]==0){
			i++;
		}
		if(a[j]==0){
			j--;
		}
	}
	cout<<ans;
	return 0;
}
