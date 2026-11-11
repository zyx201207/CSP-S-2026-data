#include<bits/stdc++.h>
using namespace std;
long long re[35],ans=0;
int a[200005][35]={},b[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	re[0]=1;
	for(int i=1;i<35;i++){
		re[i]=re[i-1]*2;
	}
	long long n,m;
	long long ans=0;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		long long x,id=0;
		cin>>x;
		while(x>0){
			a[i][id++]=x%2;
			x/=2;
		}
	}
	
	for(int i=34;i>=0;i--){
		int c[200005]={};
		long long s=0;
		for(long long j=0;j<n;j++){
			if(a[j][i]==1&&b[j]==0){
				s++;
				c[j]=1;
			}
		}
		if(s>=m){
			
			ans+=re[i];
			for(long long j=0;j<n;j++){
				if(c[j]==0){
					b[j]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
