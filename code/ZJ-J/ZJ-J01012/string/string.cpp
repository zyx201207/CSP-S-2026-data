#include <bits/stdc++.h>
using namespace std;
int i,a[201000],n,t,w;
long long ans;
char ch[201000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i]>>ch[i];
	t=1;w=n;
	while(t<=w){
		if(ch[t]==ch[w])
			if(a[t]>a[w])a[t]-=a[w],w--;
			else if(a[t]<a[w])a[w]-=a[t],t++;
			else t++,w--;
		else if(ch[t]!=ch[w])
			if(a[t]<a[w])ans+=a[t],a[w]-=a[t],t++;
			else if(a[t]>a[w])ans+=a[w],a[t]-=a[w],w--;
			else ans+=a[t],t++,w--;
	}
	cout<<ans;
	return 0;
}
