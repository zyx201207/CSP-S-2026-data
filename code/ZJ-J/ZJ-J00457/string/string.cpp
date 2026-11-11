#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char b;
}s[200005];
int pl=1,pr,n,cnt;
long long fl[200005],fr[200005],ans,sum,t,l=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	for (int i=1;i<=n;i++){
		fl[i]=fl[i-1]+s[i].a;
	}
	for (int i=n;i>=1;i--){
		fr[i]=fr[i+1]+s[i].a;
	}
	sum=fl[n]/2;
	pr=n;
	while (l<sum){
		t=l;
		if (fl[pl]<fr[pr]){
			l=fl[pl];
			if (l>sum){
				if (s[pl].b!=s[pr].b) ans+=sum-t;
			}
			if (s[pl].b!=s[pr].b) ans+=fl[pl]-t;
			pl++;
		}
		else if (fl[pl]==fr[pr]){
			l=fl[pl];
			if (l>sum){
				if (s[pl].b!=s[pr].b) ans+=sum-t;
			}
			if (s[pl].b!=s[pr].b) ans+=fl[pl]-t;
			pl++;
			pr--;
		}
		else{
			l=fr[pr];
			if (l>sum){
				if (s[pl].b!=s[pr].b) ans+=sum-t;
			}
			if (s[pl].b!=s[pr].b) ans+=fr[pr]-t;
			pr--;
		}
	}
	cout<<ans;
}
