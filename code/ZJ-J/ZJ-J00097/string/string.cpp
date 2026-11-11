#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		c[i]=getchar();c[i]=getchar();
	}
	long long i=1,j=n;
	long long ans=0;
	while(i<j){
		if(i==j){
			break;
		}
		if(a[i]>=a[j]){
			while(a[i]>0){
				int h=a[i]<a[j]?a[i]:a[j];
				if(c[i]!=c[j]){
					ans+=h;
					a[i]-=h;
					a[j]-=h;
					if(a[j]==0){
						j--;
					}
				}
				else if(c[i]==c[j]){
					a[i]-=h;
					a[j]-=h;
					if(a[j]==0){
						j--;
					}
				}
				if(a[i]==0){
					i++;
				}
				if(a[j]==0){
					j--;
				}
			}
		}
		else if(a[i]<a[j]){
			while(a[j]>0){
				int h=a[i]<a[j]?a[i]:a[j];
				if(c[i]!=c[j]){
					ans+=h;
					a[i]-=h;
					a[j]-=h;
					if(a[i]==0){
						i++;
					}
				}
				else if(c[i]==c[j]){
					a[i]-=h;
					a[j]-=h;
					if(a[i]==0){
						i++;
					}
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}