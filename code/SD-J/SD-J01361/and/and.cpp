#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int main(){
	freopen("and.in","r",stdin);
	int n,m,maxx=0;
	long long a[N];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int b,c=16,z=0;
		cin>>b;
		while(c!=1){
			if(b/c!=0){
				b-=c;
				z++;
			}
			else{
				z*=10;
				c/=2;
			}
		}
		a[i]=z;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int x=a[i],y=a[j],c=1,sum=0;
			while(x!=0 && y!=0){
				if((x%10==y%10) && x%10==1) sum+=c;
				x/=10;
				y/=10;
				c*=2;
			}
			maxx=max(maxx,sum);
		}
	}
	cout<<maxx;
	freopen("and.out","w",stdout);
	return 0;
}
