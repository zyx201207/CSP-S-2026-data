#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		k+=a[i];
	}	
	long long op,l,r=0,k;
	long long aa1,bb1;
	char aa2,bb2;
	if(k%2==0){
		op=k/2;
		for(long long i=1;i<=n;i++){
			r+=a[i];
			if(r>=op){
				l=r-a[i];
				k=i;
			}
		}
		aa1=op-l,bb1=r-op;
		aa2=c[k],bb2=c[k];
	}	
	else{
		op=k/2+1;
		for(long long i=1;i<=n;i++){
			r+=a[i];
			if(r>=op){
				l=r-a[i];
				k=i;
			}
		}
		aa1=op-l-1,bb1=r-op;
		aa2=c[k],bb2=c[k];
	}
	long long x=a[1],y=a[n],nx=1,ny=n;
	char xx=c[1],yy=c[n];
	while(nx<=ny){
		if(x>y){
			if(xx!=yy){
				ans+=y;
			}
			x=x-y;
			ny--;
			if(ny==k){
				y=bb1;
				yy=bb2;
			}
			else{
				y=a[ny];
				yy=c[ny];
			}	
		}
		else if(x<y){
			if(xx!=yy){
				ans+=x;
			}
			y=y-x;
			nx++;
			if(nx==k){
				x=aa1;
				xx=aa2;
			}
			else{
				x=a[nx];
				xx=c[nx];
			}	
		}
		else{
			if(xx!=yy){
				ans+=x;
			}
			ny--;
			nx++;
			if(nx==k){
				x=aa1;
				xx=aa2;
			}
			else{
				x=a[nx];
				xx=c[nx];
			}	
			if(ny==k){
				y=bb1;
				yy=bb2;
			}
			else{
				y=a[ny];
				yy=c[ny];
			}
		}
	}
	cout<<ans;	
	return 0;
}
