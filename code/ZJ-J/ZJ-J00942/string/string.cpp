#include<bits/stdc++.h>
using namespace std;
int n,num;
long long a[200010];
char c[200010];
long long ans;
long long l,r,ln,rn;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int cc=0;char ch;cin>>cc>>ch;
		if(ch==c[num]){a[num]+=cc;}else{a[++num]=cc;c[num]=ch;}
	}
	n=num;
	if(n==1){cout<<"0";return 0;}
	l=1,r=n;
	while(1){
		if(l==r||l>r)break;
		if(a[l]-ln<a[r]-rn){
			if(c[l]!=c[r])ans+=a[l]-ln;
			rn+=a[l]-ln;
			l++;ln=0;
		}else if(a[l]-ln==a[r]-rn){
			if(c[l]!=c[r])ans+=a[l]-ln;
			l++;r--;
			ln=0;rn=0;
		}else{
			if(c[l]!=c[r])ans+=a[r]-rn;
			ln+=a[r]-rn;
			r--;rn=0;
		}
		
	}
	cout<<ans;
	return 0;
}
