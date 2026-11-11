#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0,t=0;
long long a[200005];
char c[200005];
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int t=n;
	for(int i=1;i<=n/2;i++){
		int k=a[i];
		if(i<t){
			while(k>0){
		 		if(k>a[t]){
			 		if(c[i]!=c[t]){
						cnt+=a[t];
					}
					k-=a[t];
					t--;
				}else if(k<a[t]){
					if(c[i]!=c[t]){
						cnt+=k;
					}
					k=0;
					c[t]-=k;
				}else if(k==a[t]){
					if(c[i]!=c[t]){
						cnt+=k;
					}
					k=0;
					t--;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
