#include<bits\stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
ll n,a[N],m,ans,jz[50];
string s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	jz[1]=2;
	ll uuu=2;
	while(uuu<=32){
		jz[uuu]=jz[uuu-1]*2;
		uuu++;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ll k=a[i];
		while(k){
			if(k%2==1){
				s[i]+='1';
			}else{
				s[i]+='0';
			}
			k/=2;
		}
	}
	ll r=30;
	while(r--){
		ll x=0,y=0;
		for(int i=n;i>=1;i--){
			if(s[i].size()-1>=r){
				if(s[i][r]=='1'){
					x=max(x,a[i]);
					y++;
				}
			}else{
				break;
			}
		}
		if(y>=m){
			y--;
			ll cnt=1;
			for(int i=n;i>=1&&y>0;i--){
				if(s[i][r]='1'){
					x=x&a[i];
				}
			}
		}else{
			for(int i=n;i>=1;i--){
			if(s[i].size()-1>=r){
				if(s[i][r]=='1'){
					a[i]-=jz[r];
				}
			}else{
				break;
			}
		}
		}
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}