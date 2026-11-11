#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int x=1,y=n;
	while(x<y){
		if(a[x]>a[y]){
			a[x]-=a[y];
			if(c[x]!=c[y])ans+=a[y];
			y--;
		}else if(a[x]<a[y]){
			a[y]-=a[x];
			if(c[x]!=c[y])ans+=a[x];
			x++;
		}else{
			if(c[x]!=c[y])ans+=a[x];
			x++;
			y--;
		}
	}
	cout<<ans;
	return 0;
}
