#include <bits/stdc++.h>
using namespace std;
long long n,i,a[200010],t,w,s;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i]>>c[i];
	t=1;w=n;
	while(t<=w){
		if(c[t]!=c[w]) s+=min(a[t],a[w]);
		if(a[t]<a[w]) a[w]-=a[t],t++;
		else if(a[t]>a[w]) a[t]-=a[w],w--;
		else t++,w--;
	}
	cout<<s;
	return 0;
}
