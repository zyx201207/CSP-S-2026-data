#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int c[500005];
int d[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int mi=0;
	long long n,m,f,e=1,h=0,k=1,s=1,r=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=m;i++){
		b[i]=i;
		c[i]=0;
	}
	f=a[k];
	r=n;
	while(n--){
		for(long long i=s;i<=r;i++){
			if(f==a[i]){
				f=a[i];
				h=i;
			}
			if(i==n){
				for(long long j=h;j<=r;j++){
					if(a[j+2]!=0){
						mi=min(a[j+1],a[j+2]);
						a[j]=min(a[j],mi);
					}else if(a[j+1]!=0){
						a[j]=min(a[j+1],a[j]);
					}
				}
				for(long long j=1;j<=m;j++){
					if(a[h]==b[e] && h<=r){
						c[e]++;
						h++;
					}
					e++;
				}
			}
		}
		k++,f=a[k],h=0,s=k,e=1;
	}
	for(long long i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
