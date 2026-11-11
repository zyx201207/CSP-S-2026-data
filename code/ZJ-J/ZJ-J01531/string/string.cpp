#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,sumn;
int a[200086];
char c[200086];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,llen=a[1],rlen=a[n];
	while(l<r){
		if(llen>rlen){
			if(c[l]!=c[r])ans+=rlen;
			llen-=rlen;
			r--;rlen=a[r];
		}
		else if(rlen>llen){
			if(c[l]!=c[r])ans+=llen;
			rlen-=llen;
			l++;llen=a[l];
		}
		else{
			if(c[l]!=c[r])ans+=llen;
			rlen=llen=0;
			l++;llen=a[l];
			r--;rlen=a[r];
		}
	}
	cout<<ans;
	return 0;
}