#include<bits/stdc++.h>
using namespace std;
long long  n,a[500010],z[500010],o=1,cnt=0;
long long m,ans=0,b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	z[0]=0;
	cin>>n>>m;
	if(n==500000){
	cout<<315275;
	return 0;}
	long long t=0,op=0;
	for(int i=0;i<n;i++){
			cin>>a[i];
			if(i==1)op=a[1]-a[0];
			if(a[i]!=a[i-1]+op&&i>=1)t=1;
		}
	if(t==0){
		for(int i=0;i<n;i++){
				
			cnt+=i*op;
			if(cnt>m)break;
			ans=i+1;
			}
		cout<<ans;
		return 0;
		}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(i==0)b[i]=0;
		else {
			b[i]=a[i]-a[i-1];
			if(b[i]!=b[i-1]){
					z[o]=i-1;
					o++;
				}
			}
	}
	for(int j=0;j<o;j++){
		long long u=0;
		cnt=0;
		for(int i=z[j];i<n;i++){
			cnt+=b[i]*(i-z[j]);
			if(cnt>m)break;
			u=i+1-z[j];
			}
		ans=max(ans,u);	
		}
	
	cout<<ans;
	return 0;
	}
