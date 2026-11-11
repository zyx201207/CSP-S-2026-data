#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m,s[500010],q,p,a,b,c,ans;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	
	for(int i=0;i<=n;i++){
		q=0;
		for(int j=2;j<=n;j++){
			if(s[i-1]>s[i]){
				p=s[i];
				s[i]=s[i-1];
				s[i-1]=p;
				q=1;
			}
		}
		if(q==0)break;
	}
	
	ans=0;
	
	for(int i=2;i<=n;i++){
		c=m;
		for(int j=i;j>=1;j--){
			c=c-s[i]+s[j];
			if(c<0&&j>1){
				a=j+1;
				break;
			}
			if(a==1)a=j;
		}
		b=i-a+1;
		if(ans<b)ans=b;
	}
	
	cout<<ans;
	
	return 0;
}
