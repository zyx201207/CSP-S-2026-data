#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],d[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	int ans;int no=1;int l=1,r=n;int b;
	while(r>l){
		no=0;
		ans=(l+r)/2;
		for(int i=2;i<=n;i++){
			if(i<ans){
				s[i]=s[i-1]+d[i]*(i-1);
				continue;
			}
			else if(i>=ans&&i<ans+2){
				s[i]=s[i-1]+d[i]*(i-1);
			}
			else if(i>=ans+2){
				s[i]=ans*d[i]+s[i-1]-a[i-1]+a[i-ans];
			}
			if(s[i]<=m){
				no=1;
			}
		}
		if(no){
			l=ans+1;
			b=ans;
		}
		else{
			r=ans-1;
		}
	}
	ans=b+1;
	no=0;
	for(int i=2;i<=n;i++){
		if(i<ans){
			s[i]=s[i-1]+d[i]*(i-1);
			continue;
		}
		else if(i>=ans&&i<ans+1){
			s[i]=s[i-1]+d[i]*(i-1);
		}
		else if(i>=ans+2){
			s[i]=(ans-1)*d[i]+s[i-1]-a[i-1]+a[i-ans];
		}
		if(s[i]<=m){
			no=1;
			break;
		}
	}
	if(no){
		b=ans;
	}
	cout<<b;
	return 0;
}