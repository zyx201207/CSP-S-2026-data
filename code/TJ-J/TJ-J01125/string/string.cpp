#include<bits/stdc++.h>
#define ll long long
using namespace std;const int N=2e5+5;
int n;char c[N];ll a[N],ans;
int main(){freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}int l=1,r=n;ll pl=a[1],pr=a[n];
	while(1){
		if(l>=r)break;
		if(pl==pr){
			if(c[l]!=c[r])ans+=pl;
			pl=a[++l];pr=a[--r];
		}
		else if(pl<pr){
			if(c[l]!=c[r])ans+=pl;
			pr-=pl;pl=a[++l];
		}
		else{
			if(c[l]!=c[r])ans+=pr;
			pl-=pr;pr=a[--r];
		}
	}cout<<ans;
	return 0;
}
