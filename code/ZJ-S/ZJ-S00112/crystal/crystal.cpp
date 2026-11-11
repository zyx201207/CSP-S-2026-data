#include<bits/stdc++.h>
using namespace std;
long long n,m,v=0,s=0,t=1;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	v=m;
	if(n>5000){
		long long l=0,k=a[n/2+1]-a[n/2];
		for(long long i=1;i<n;i++){
			l+=i*k;
			if(l>m){
				s=i;
				break;
			}
			else if(l<=m){
				s=i+1;
			}
		}
	}
	else{
		for(long long i=n-1;i>=1;i--){
			if(a[i+1]-a[i]>v){
				continue;
			}
			else{
				for(long long j=a[i+1];j>=a[i];j--){
					for(long long k=i-1;k>=1;k--){
						if(j-a[i]+j-a[k]<=v){
							v-=j-a[i]+j-a[k];
							t++;
							if(i==n-1&&k==i-1&&a[n]==j){
								t++;
							}
						}
						else{
							break;
						}
					}
					v=m;
					s=max(s,t);
					t=1;
				}
				if(s==n){
					break;
				}	
			}
		}
	}
	cout<<s;
	return 0;
}