#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n;
long long a[N];
char c[N];
long long hzt;
int vis[N];
int t=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			while(a[i]){
				if(n-i+1-t<=i) break;
				if(a[n-i+1-t]<a[i]){
					a[i]-=a[n-i+1-t];
					vis[n-i+1-t]=1;
					if(c[i]!=c[n-i+1-t]){
						hzt+=a[n-i+1-t];
					}
					t++;
				}else{
					if(a[n-i+1-t]==a[i]){
						a[i]-=a[n-i+1-t];
						vis[n-i+1-t]=1;
						if(c[i]!=c[n-i+1-t]){
							hzt+=a[n-i+1-t];
						}
					}else{
						a[n-i+1-t]-=a[i];
						if(c[i]!=c[n-i+1-t]){
							hzt+=a[i];
						}
						t-=1;
						a[i]=0;
					}
				}
			}
		}
	}
	cout<<hzt<<'\n';
	return 0;
} 
