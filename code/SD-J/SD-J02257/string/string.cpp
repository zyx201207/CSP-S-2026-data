#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int x=1,y=n;
	long long sum=0;
	while(x<y){
		if(a[x]!=a[y]){
			if(a[x]>a[y]){
				if(c[x]!=c[y]){
					sum+=a[x]-a[y];
					a[x]-=a[y];
					y--;
				}else{
					a[x]-=a[y];
					y--;
				}
			}else{
				if(c[x]!=c[y]){
					sum+=a[y]-a[x];
					a[y]-=a[x];
					x++;
				}else{
					a[y]-=a[x];
					x++;
				}
			}
		}else{
			if(c[x]!=c[y]){
				sum+=a[x];
				x++;
				y--;
			}else{
				x++;
				y--;
			}
		}
	}
	cout<<sum;
	return 0;
}

