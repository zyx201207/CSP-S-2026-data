#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ma;
long long m,a[N],p[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=5000){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++) p[j]=a[j]-a[j-1];
			long long s=0;
			int x=i+1;
			for(int j=i+1;j<=n;j++){
				s+=p[j]*(j-i);
				if(s<=m){
					x=j;
				}else{
					break;
				}
			}
			ma=max(ma,x-i+1);
		}
		cout<<ma;
	}else{
		long long q=a[2]-a[1];
		long long s=0;
		int x=1;
		for(int j=1;j<=n;j++){
			s+=q*j;
			if(s<=m){
				x=j;
			}else{
				break;
			}
		}
		ma=max(ma,x);
		cout<<ma;
	}
}
