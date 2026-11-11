#include<bits/stdc++.h>
using namespace std;
long long n,ans,ln,cnt,l[500000],r[500000],nn[500000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int len;
		char nw;
		l[i]=ln+1;
		cin>>len>>nw;
		ln+=len;
		r[i]=ln;
		nn[i]=nw-'a';
	}
	for(int i=1;i<=n;i++){
		if(l[i]>=ln/2)break;
		int fr=ln+1-l[i];
		int fl=ln+1-r[i];
		int lw=lower_bound(r+1,r+1+n,fl)-r;
		int rw=lower_bound(l+1,l+1+n,fr)-l;
		if(r[lw-1]>=fl&&nn[i]!=nn[lw-1]){
			ans+=r[lw-1]-fl+1;
			
		}
		for(int j=lw;j<rw;j++){
			if(nn[i]!=nn[j])ans+=r[j]-l[j]+1;
			
		}
	}
	
	cout<<ans;
	return 0;
}
