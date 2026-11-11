#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,a[N],m,d[N],s[N],ans=1,flag=0;
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1]; 
		if(d[i]!=d[i-1]&&i!=2&&flag==0)flag=1;
	}
	if(flag==0){
		ll count=1;
		ll cha=d[3];
		ll cnt=1;
		while(m>=cnt*cha){
			cnt+=(cnt+1);
			count++;
		}
		cout<<count<<'\n';
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(m-d[i]*(i-1)>=0){
			m-=d[i]*(i-1);
			ans++;
		}
		else break;
	}
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
