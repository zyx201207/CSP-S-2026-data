#include<bits/stdc++.h>
using namespace std;
long long crys[10005],d[10005],c[10005][10005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,best;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>crys[i];
	}
	for(int i=n;i>0;i--){
		d[i-1]=crys[i]-crys[i-1];
	}
	for(int i=0;i<n;i++){
		for(int j=i-1;j>=0;j--){
			c[i][j]=d[j]+c[i][j-1];
		}
	}
	for(int i=0;i<n;i++){
		ans=max(ans,best);
		best=0;
		long long cnt;
			cnt=m;
		for(int j=i-1;j>=0;j--){
			if(cnt>d[j]){
				best++;
				cnt-=d[j];
			}else{
				break;
			}
		}
	}
	cout<<ans+1;
	return 0;
}
