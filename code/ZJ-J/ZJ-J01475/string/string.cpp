#include<bits/stdc++.h>
using namespace std;
int n,a[200011],a1[200011];
long long f[200011],f1[200011],o[200011],o1[200011],ans=0;
char ch[200011],ch1[200011];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		a1[n-i+1]=a[i];
		ch1[n-i+1]=ch[i];
	}
	f[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	f1[0]=0;
	for(int i=1;i<=n;i++){
		f1[i]=f1[i-1]+a1[i];
	}
	o[0]=0;
	for(int i=1;i<=n+1;i++){
		o[i]=f[i-1]+1;
	}
	o1[0]=0;
	for(int i=1;i<=n+1;i++){
		o1[i]=f1[i-1]+1;
	}
	for(int i=1;i<=n;i++){
		int x=0,y=0;
		int L=0,R=n+1;
		while(L+1<R){
			int M=(L+R)/2;
			if(o1[M]<=o[i]){
				L=M;
			}
			else{
				R=M;
			}
		}
		x=L;
		L=0,R=n+1;
		while(L+1<R){
			int M=(L+R)/2;
			if(o1[M]<=o[i+1]-1){
				L=M;
			}
			else{
				R=M;
			}
		}
		y=L;
		if(x==y){
			ans+=o[i+1]-o[i];
		}
		else{
			for(int j=x;j<=y;j++){
				if(ch[i]!=ch1[j]){
					if(j==x){
						ans+=o1[j+1]-o[i];
					}
					else
					if(j==y){
						ans+=o[i+1]-o1[j];
					}
					else{
						ans+=o1[j+1]-o1[j];
					}
				}
			}		
		}
	}
	cout<<ans/2<<'\n';
	return 0;
}