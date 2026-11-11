#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char op[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		char c;
		cin>>c;
		op[i]=c;
	}
	long long x=1;
	long long y=n;
	long long ans=0;
	while(x<y){
		if(op[x]==op[y]){
			if(a[x]<a[y]){
				a[y]-=a[x];
				a[x]=0;
				x++;
			}else if(a[x]>a[y]){
				a[x]-=a[y];
				a[y]=0;
				y--;
			}else{
				a[x]=0;
				a[y]=0;
				x++;
				y--;
			}
		}else{
			if(a[x]<a[y]){
				ans+=a[x];
				a[y]-=a[x];
				a[x]=0;
				x++;
			}else if(a[x]>a[y]){
				ans+=a[y];
				a[x]-=a[y];
				a[y]=0;
				y--;
			}else{
				ans+=a[x];
				a[x]=0;
				a[y]=0;
				x++;
				y--;
			}
		}
	}
	cout<<ans;
	return 0;
}

