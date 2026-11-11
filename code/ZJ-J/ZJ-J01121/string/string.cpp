#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200010;
ll n,t,i,w,flag,l[N],ans,sum;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	t=1;
	for(i=1;i<=n;i++)
		cin>>l[i]>>c[i],sum+=l[i];
	t=1;w=n;
	while(t<w){
		if(c[t]!=c[w])flag=1;
		else flag=0;
		if(l[t]>l[w])ans+=l[w]*flag,l[t]-=l[w],w--;
		else if(l[t]==l[w]){
			ans+=l[t]*flag;
			t++,w--;
		}
		else ans+=l[t]*flag,l[w]-=l[t],t++;
	}
	cout<<ans;
	return 0;
}

