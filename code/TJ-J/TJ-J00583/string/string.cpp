#include <bits/stdc++.h>
using namespace std;
const int N=200005;
long long a[N];
char u[N];
int main(){
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>u[i];
	}
	long long m=n/2;m+=n%2;
	long long x=0;
	long long j=0;
	long long s=0;
	for(long long i=0;i<m;i++){
		if(x){
			if(u[j]==u[n-i-1]){
				if(a[j]==a[n-i-1]){
					x=0;
					continue;
				}else{
					x+=max(x,a[n-i-1])-min(x,a[n-i-1]);
					if(x>a[n-i-1]){
						j=j;
					}else{
						j=n-i-1;
					}
				}
			}else{
				s+=min(x,a[n-i-1]);
				if(x==a[n-i-1]){
					x=0;
					continue;
				}else{
					x+=max(x,a[n-i-1])-min(x,a[n-i-1]);
					if(x>a[n-i-1]){
						j=j;
					}else{
						j=n-i-1;
					}
				}
			}
		}else{
			if(u[i]==u[n-i-1]){
				if(a[i]==a[n-i-1]){
					continue;
				}else{
					x+=max(a[i],a[n-i-1])-min(a[i],a[n-i-1]);
					j=i;
				}
			}else{
				s+=min(a[i],a[n-i-1]);
				if(a[i]==a[n-i-1]){
					continue;
				}else{
					x+=max(a[i],a[n-i-1])-min(a[i],a[n-i-1]);
					if(a[i]>a[n-i-1]){
						j=i;
					}else{
						j=n-i-1;
					}
				}
			}
		}
	}
	cout<<s;
	return 0;
}

