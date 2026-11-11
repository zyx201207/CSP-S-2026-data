#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[200010];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	int v=1,sum=0;
	for(int i=1;i<=n;i++){
		int sum1=0;
		for(int j=i;j<=n;j++){
			int x[100086],x1=a[i]/2,x2=a[j]%2;
			int y[100086],y1=a[j]/2,y2=a[j]%2;
			for(int c=1;c<=x1;c++){
				x[i]=1;
			}
			x[x1+1]=x2;
			for(int c=1;c<=y1;c++){
				y[i]=1;
			}
			y[y1+1]=y2;
			for(int i=1;i<=100000;i++){
				if(x[i]==1&&x[i]==y[i]){
					sum1++;
				}
			}
		}
		sum=max(sum,sum1);
	}
	cout<<sum;
	return 0;
}