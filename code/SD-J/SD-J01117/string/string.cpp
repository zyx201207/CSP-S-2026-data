#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long cnt;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
	}
	int x=1;
	int y=n;
	while(x<y){
		if(c[x]==c[y]){
			if(a[x]>a[y]){
				a[x]-=a[y];
				y--;
			}
			else if(a[x]<a[y]){
				a[y]-=a[x];
				x++;
			}
			else{
				x++;
				y--;
			}
		}
		else{
			if(a[x]>a[y]){
				cnt+=a[y];
				a[x]-=a[y];
				y--;
			}
			else if(a[x]<a[y]){
				cnt+=a[x];
				a[y]-=a[x];
				x++;
			}
			else{
				cnt+=a[x];
				x++;
				y--;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}
