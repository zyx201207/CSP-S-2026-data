#include <bits/stdc++.h>
using namespace std;
void fre(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}
long long n,a[200010],s,s1,l,r,l1,r1,ans,p,p1,z[200010],d[200010];
char c[200010];
string ss;
void pian(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			ss+=c[i];
		}
	}
	long long k=ss.size();
	ss=" "+ss;
	for(int i=1;i<=k/2;i++){
		if(ss[i]!=ss[k-i+1]){
			ans++;
		}
	}
	cout<<ans;
}
int main(){
	fre();
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		s+=a[i];
		z[i]=s+1;
		d[i]=s;
	}
	if(s<=1e8){
		pian();
		return 0;
	}
	l=1;r=n;
	l1=1;r1=s;
	while(l1<=(s/2)&&((s+1)/2)+1<=r1){
		if(c[l]==c[r]){
			p=z[l]-l1;
			p1=r1-d[r];
			if(z[l]<=d[r]){
				if(z[l]==d[r]){
					l1+=p;
					r1-=p1;
				}
				else{
					l1+=p;
					r1-=p;	
				}
			}
			else{
				l1+=p1;
				r1-=p1;
			}
		}
		else{
			p=z[l]-l1;
			p1=r1-d[r];
			if(z[l]<=d[r]){
				if(z[l]==d[r]){
					l1+=p;
					r1-=p1;
					ans+=p;
				}
				else{
					l1+=p;
					ans+=p;
					r1-=p;	
				}
			}
			else{
				l1+=p1;
				ans+=p1;
				r1-=p1;
			}
		}
		while(l1>=z[l]){
			l++;
		}
		while(r1<=d[r]){
			r--;
		}
	}
	cout<<ans;
}
