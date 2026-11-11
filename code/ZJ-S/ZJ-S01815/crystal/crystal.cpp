#include<bits/stdc++.h>
using namespace std;
long long sum[500005],n,m,a[500005],c[500005],ans=0,l,r,A,M;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)c[n-i+1]=a[i];
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+c[i];
	}
	for(int i=1;i<=n;i++){
		l=i;r=n;
		while(r>=l){
			M=(l+r)>>1;
			if((M-i+1)*c[i]-(sum[M]-sum[i-1])<=m){
				ans=max(ans,M-i+1);
				l=M+1;
			}
			else r=M-1;
		}
	}
	cout<<ans;
} 
//5 5
//2 1 2 4 8 9
//5 8
 //-3 -1 2 2 7