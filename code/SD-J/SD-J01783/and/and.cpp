#include<iostream>
using namespace std;
long long a[200005],b[200005];
long long x,y,z,maxx=-1,u,maxxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxxx=max(a[i],maxxx);
		}
		cout<<maxxx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]&a[j]>maxx){
					maxx=a[i]&a[j];
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		u=a[1];
		for(int i=2;i<=n;i++){
			u&=a[i];
		}
		cout<<u;
		return 0;
	}
	if(m==n-1){
		u=a[1];
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				u&=a[i];
			}
			for(int j=i+1;j<=n;j++){
				u&=a[i];
			}
			if(u>maxx){
				maxx=u;
			}
		}
		cout<<maxx;
		return 0;
	}
	cout<<y;
	return 0;
}
