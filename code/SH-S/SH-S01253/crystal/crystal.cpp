#include<bits/stdc++.h>
using namespace std;
long long a[500010],s[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,c=1,d=0,mx=1;
	int st=n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	st=n;
	for(int st=n;st>1;st--){
		for(int i=st-1;i;i--){
			if(d+s[st]-s[i]<=m){
				d=d+s[st]-s[i];
				c++;
			}else{
				break;
			}
		}
		mx=max(mx,c);
		d=0;
		c=1;
	}
	mx=max(mx,c);
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
}
