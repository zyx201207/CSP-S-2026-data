#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long n,a[200005],m,ans,p[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		p[i]=p[i-1]+a[i];
		m+=a[i];
	}
	long long l=0,r=m;
	int l_=1,r_=n-1;
	while(l<r){
		if(p[l_]-l>r-p[r_]){
			//cout<<"> ";
			if(c[l_]!=c[r_+1]) ans+=r-p[r_];
			l+=r-p[r_],r=p[r_--];
			//cout<<l<<' '<<r<<' '<<l_<<' '<<r_<<' '<<ans<<'\n';
		}else if(p[l_]-l<r-p[r_]){
			//cout<<"< ";
			if(c[l_]!=c[r_+1]) ans+=p[l_]-l;
			r-=p[l_]-l,l=p[l_++];
			//cout<<l<<' '<<r<<' '<<l_<<' '<<r_<<' '<<ans<<'\n';
		}else{
			//cout<<"= ";
			if(c[l_]!=c[r_+1]) ans+=p[l_]-l;
			l=p[l_++],r=p[r_--];
			//cout<<l<<' '<<r<<' '<<l_<<' '<<r_<<' '<<ans<<'\n';
		}
	}
	cout<<ans;	
}