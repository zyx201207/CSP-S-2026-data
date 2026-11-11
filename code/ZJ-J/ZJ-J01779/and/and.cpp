#include<bits/stdc++.h>
#define max(a,b) (a>b?a:b)
using namespace std;
int n,m,mx,s,a[200100],c[50];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	mx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int e=0,x=a[i];
		while(x){
			c[e]+=x%2;
			e++;x/=2;
		}
	}
	for(int i=0;i<=30;i++) mx=(c[i]<m?mx:i);
	while(mx!=-1){
		int q=mx;
		int ch=pow(2,q),mod=pow(2,q+1);
		mx=-1;
		s+=pow(2,q);
		for(int i=1;i<=n;i++){
			if(a[i]%mod/ch<1){
				int e=0,x=a[i];
				while(x){
					c[e]-=x%2;
					e++;x/=2;
				}
				a[i]=0;	
			}
		}
		for(int i=0;i<q;i++) mx=(c[i]<m?mx:i);
	}
	cout<<s;
	return 0;
}