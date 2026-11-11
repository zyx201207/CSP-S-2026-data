#include<bits/stdc++.h>
using namespace std;
#define int long long
struct sstring{
	int s,e;
	char c;
};
int n;
int zh,t1,t2,li,ri,ans;
sstring a[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].e>>a[i].c;
		a[i].s=a[i-1].e+1;
		a[i].e+=a[i-1].e;
	}
	if(a[n].e%2==1){
		zh=(a[n].e+1)/2;
		for(int i=1;i<=n;i++){
			if(a[i].e>=zh){
				t1=t2=i;
				break;
			}
		}
		li=ri=zh;
		while(li>1){
			int s1=li-a[t1].s,s2=a[t2].e-ri;
			if(s1==0){
				t1--;
				s1=li-a[t1].s;
			}
			if(s2==0){
				t2++;
				s2=a[t2].e-ri;
			}
			if(a[t1].c!=a[t2].c){
				ans+=min(s1,s2);
			}
			li-=min(s1,s2),ri+=min(s1,s2);
		}
		cout<<ans;
	}
	else{
		zh=a[n].e/2;
		for(int i=1;i<=n;i++){
			if(a[i].e==zh){
				t1=i;
				t2=i+1;
				break;
			}
			if(a[i].e>zh){
				t1=t2=i;
				break;
			}
		}
		li=zh,ri=zh+1;
		if(a[t1].c!=a[t2].c) ans=1;
		while(li>1){
			int s1=li-a[t1].s,s2=a[t2].e-ri;
			if(s1==0){
				t1--;
				s1=li-a[t1].s;
			}
			if(s2==0){
				t2++;
				s2=a[t2].e-ri;
			}
			if(a[t1].c!=a[t2].c){
				ans+=min(s1,s2);
			}
			li-=min(s1,s2),ri+=min(s1,s2);
		}
		cout<<ans;
	}
}