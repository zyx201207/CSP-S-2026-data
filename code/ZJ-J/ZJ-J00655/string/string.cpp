#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long y=a[n];
	long long x=a[1];
	int d=1,e=n;
	long long ans=0;
	while(d<e){
		if(x>y){
			if(c[d]==c[e]){
				x-=y;
				e--;
				y=a[e];
			}else{
				x-=y;
				ans+=y;
				y=a[--e];
			}
		}
		else if(y>x){
			if(c[d]==c[e]){
				y-=x;
				x=a[++d];
			}else{
				ans+=x;
				y-=x;
				x=a[++d];
			}
		}
		else if(x==y){
			if(c[e]==c[d]){
				x=a[++d];
				y=a[--e];
				continue;
			}else{
				ans+=x;
				x=a[++d];
				y=a[--e];
			}
		}
	}
	cout<<ans;
	return 0;
}