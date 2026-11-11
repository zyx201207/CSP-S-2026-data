#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,p=n,x=a[n],y=0;i<=n;i++){
		if(i>=p)break;
		y=a[i];
		if(x>y){
			x-=y;
			ans+=y*(c[i]!=c[p]);
		}else if(x==y){
			ans+=y*(c[i]!=c[p]);
			x=0;
		}
		else{
			y-=x;
			ans+=x*(c[i]!=c[p]);
			p--;
			while(i<p&&y>a[p]){
				y-=a[p];
				ans+=a[p]*(c[i]!=c[p]);
				p--;
			}x=a[p]-y;
			ans+=y*(c[i]!=c[p]);
		}
	}cout<<ans;
	return 0;
}
