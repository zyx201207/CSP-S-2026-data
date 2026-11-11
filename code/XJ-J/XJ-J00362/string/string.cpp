#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],l,r,s,dl,dr,ans,cl,cr;
char c[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],s+=a[i];
	r=s,l=dl=1,dr=n,cl=a[1],cr=a[n];
	while(r-l>1){
		if(cl<cr){
			if(l+cl>s/2)cl=s/2+1-l;
			if(c[dl]!=c[dr])ans+=cl;
			r-=cl,l+=cl,cr-=cl,cl=a[++dl];
		}else if(cl>cr){
			if(r-cr<s/2+1)cr=r-s/2-1;
			if(c[dl]!=c[dr])ans+=cr;
			r-=cr,l+=cr,cl-=cr,cr=a[--dr];
		}else{
			if(l+cl>s/2)cl=s/2-l;
			if(c[dl]!=c[dr])ans+=cl;
			r-=cl,l+=cl,cl=a[++dl],cr=a[--dr];
		}
	}
	if(c[dl]!=c[dr])ans++;
	cout<<ans;
	return 0;
}
