#include<bits/stdc++.h>
using namespace std;
int n,s,ans,t;
long long m,a[500005],x;
bool b;
int main(){
	freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);	
	x=a[2]-a[1];
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=x){
			b=1;
			break;
		}
	}
	if(b==0){
		for(int i=1;i<=n;i++){
			if((x+i*x)*i/2>m){
				cout<<i;
				return 0;
			}
		}
	}
	for(int i=2;i<=n;i++){
		t=i-1;
		s=0,x=m;
		while(t>0&&x>=a[i]-a[t]){
			s++;
			x=x-a[i]+a[t];
			t--;
		}
		ans=max(s,ans);
	}
	cout<<ans+1;
	return 0;
}