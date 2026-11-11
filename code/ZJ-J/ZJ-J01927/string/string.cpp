#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
long long sum,h,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	h=(sum+1)/2;
	int lx=1,ul,rx=n,ur;
	long long l=0,r=sum+1;
	while(l<h&&r>h){
		int s1=a[lx]-ul,s2=a[rx]-ur;
		s1=min(s1,s2);
		s2=min(s1,s2);
		if(c[lx]==c[rx]){
			l+=s1;
			r-=s2;
			ul+=s1;
			ur+=s2;
		}else{
			ans+=s1;
			l+=s1;
			r-=s2;
			ul+=s1;
			ur+=s2;
		}
		if(ul==a[lx]){
			lx++;
			ul=0;
		}if(ur==a[rx]){
			rx--;
			ur=0;
		}
	}
	cout<<ans;
	return 0;
}
