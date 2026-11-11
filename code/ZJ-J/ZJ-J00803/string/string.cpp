#include<bits/stdc++.h>
using namespace std;
const int MX=(1e5+5)*2;
char c[MX];
int n;
long long a[MX];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int j=1;j<=n;j++){
		cin>>a[j]>>c[j];
	}
	long long ans=0;
	long long i=1;
	while(i<n){
		if(c[i]!=c[n]){
			if(a[i]==a[n]){
				ans+=a[i];
				n--;
				i++;
				continue;
			}
			else{
				if(a[i]>a[n]){
					ans+=a[n];
					a[i]-=a[n];
					n--;
					continue;
				}
				else{
					ans+=a[i];
					a[n]-=a[i];
					i++;
					continue;
				}
			}
		}
		else{
			if(a[i]==a[n]){
				i++;
				n++;
				continue;
			}
			else{
				if(a[i]>a[n]){
					a[i]-=a[n];
					n--;
					continue;
				}
				else{
					a[n]-=a[i];
					i++;
					continue;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}