#include <bits/stdc++.h>
using namespace std;
long long n,a[200010];
string s;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	long long r,ans=0,k;
	for(int i=1;i<=n/2;i++){
		if((c[i]==c[n+1-i]&&a[i]!=a[n+1-i])||c[i]!=c[n+1-i]){
			if(a[i]==a[n+1-i])ans+=a[i];
			else if(a[i]>a[n+1-i]){
				if(c[i]==c[n+1-i]){k=1;r=a[i]-a[n+1-i];}
				else {r=a[i];k=0;}
				while(r!=0){
					if(c[n+1-i-k]==c[i]){
						if(a[n+1-i-k]>=r)break;
						else {
							ans+=a[n+1-i-k];
							r-=a[n+1-i-k];
							a[n+1-i-k]=0;
							k++;
						}
					}
					else {
						if(a[n+1-i-k]>=r){ans+=r;a[n+1-i-k]-=r;break;}
						else {ans+=a[n+1-i-k];r-=a[n+1-i-k];a[n+1-i-k]=0;k++;}
					}
				}
			}
			else {
				if(c[i]==c[n+1-i]){k=1;r=a[n+1-i]-a[i];}
				else {r=a[n+1-i];k=0;}
				
				while(r!=0){
					if(c[i+k]==c[i]){
						if(a[i+k]>=r)break;
						else {
							ans+=a[i+k];
							r-=a[i+k];
							a[i+k]=0;
							k++;
						}
					}
					else {
						if(a[i+k]>=r){ans+=r;a[i+k]-=r;break;}
						else {ans+=a[i+k];r-=a[i+k];a[i+k]=0;k++;}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
