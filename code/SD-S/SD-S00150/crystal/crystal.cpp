#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],m,p[N],maxx;
void f(long long cnt){
	if(cnt>m){
		long long ff=0,sum=0;
		for(int i=1;i<=n;i++){
			if(p[i]==1){
				if(ff==0){
					sum=a[i];
					ff=1;
				}else{
					sum=sum&a[i];
				}
			}
		}
		maxx=max(maxx,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(p[i]==0){
			p[i]=1;
			f(cnt+1);
			p[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		cout<<2;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx=maxx&a[i];
		}
		cout<<maxx;
		return 0;
	}
	
	if(n<=20&&m<=n){
		f(1);
		cout<<maxx;
		return 0;
	}
	return 0;
}
