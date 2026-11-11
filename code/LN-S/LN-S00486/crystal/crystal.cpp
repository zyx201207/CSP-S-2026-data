#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500010;
int n,m,a[N],p[N],s;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	if(a[1]-a[0]==a[2]-a[1]&&a[2]-a[1]==a[3]-a[2]){
		int x=a[1]-a[0];
		for(int i=1;i<n;i++){
			p[i]=i*(i+1)/2*x;
			if(p[i]>m){
				s=i;
				break;
			}
		}
	}else{
		for(int i=1;i<n;i++){
			for(int j=1;j<=i;j++)p[i]+=a[i]-a[i-j];
			if(p[i]>m){
				s=i;
				break;
			}
		}
	}
	cout<<s;
	return 0;
}
