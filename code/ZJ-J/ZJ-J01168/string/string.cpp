#include<bits/stdc++.h>
using namespace std;
int n,l,r,m,k;
long long ans,a[200005],p[200005],x[200005],y[200005];
char b[200005],xx[200005],yy[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		p[i]=p[i-1]+a[i];
	}
	if(p[n]%2){
		for(int i=1;i<=n;i++){
			if(p[i]>=p[n]/2+1){
				m=i;
				x[i]=p[n]/2+1;
				xx[i]=b[i];
				break;
			}else{
				x[i]=p[i];
				xx[i]=b[i];	
			}
		}
		for(int i=n;i>=1;i--){
			if(p[i-1]+1<=p[n]/2+1){
				k=n-i+1;
				y[n-i+1]=p[n]/2+1;
				yy[n-i+1]=b[i];
				break;
			}else{
				y[n-i+1]=p[n]-p[i-1];
				yy[n-i+1]=b[i];	
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(p[i]>=p[n]/2){
				m=i;
				x[i]=p[n]/2;
				xx[i]=b[i];
				break;
			}else{
				x[i]=p[i];
				xx[i]=b[i];	
			}
		}
		for(int i=n;i>=1;i--){
			if(p[i-1]+1<=p[n]/2+1){
				k=n-i+1;
				y[n-i+1]=p[n]/2;
				yy[n-i+1]=b[i];
				break;
			}else{
				y[n-i+1]=p[n]-p[i-1];
				yy[n-i+1]=b[i];	
			}
		}
	}
	l=0,r=0;
	while(l!=m||r!=k){
		if(x[l]==y[r]){
			l++;
			continue;
		}
		if(x[l]>y[r]){
			r++;
			if(y[r]<=x[l]){
				if(yy[r]!=xx[l]){
					ans+=y[r]-y[r-1];
				}
			}else{
				if(yy[r]!=xx[l]){
					ans+=x[l]-y[r-1];
				}
			}
		}else{
			l++;
			if(y[r]>=x[l]){
				if(yy[r]!=xx[l]){
					ans+=x[l]-x[l-1];
				}
			}else{
				if(yy[r]!=xx[l]){
					ans+=y[r]-x[l-1];
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
