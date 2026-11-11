#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0,x=1,y;
	cin>>n;
	y=n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	while(x<y||x==y){
		if(a[x]<a[y]){
			if(b[x]!=b[y])ans+=a[x];
			a[y]=a[y]-a[x];
			x++;
		}
		else if(a[x]>a[y]){
			if(b[x]!=b[y])ans+=a[y];
			a[x]=a[x]-a[y];
			y--;
		}
		else{
			if(b[x]!=b[y])ans+=a[x];
			x++;
			y--;
		}
	}
	cout<<ans;
	return 0;
}

