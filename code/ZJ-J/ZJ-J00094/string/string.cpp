#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],l=1,r=0,pl=0,pr=0,ans=0;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	r=n;
	while(l<r){
		if(a[l]-pl==a[r]-pr){
			if(c[l]!=c[r])ans+=a[l]-pl;
			l++;
			r--;
			pl=pr=0;
		}else if(a[l]-pl>a[r]-pr){
			if(c[l]!=c[r])ans+=a[r]-pr;
			pl+=(a[r]-pr);
			r--;
			pr=0;
		}else if(a[l]-pl<a[r]-pr){
			if(c[l]!=c[r])ans+=a[l]-pl;
			pr+=(a[l]-pl);
			l++;
			pl=0;
		}
	}
	cout<<ans;
	return 0;
}
