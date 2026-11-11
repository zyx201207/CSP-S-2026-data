#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d,e,f,g,ans;
ll aa[500005],bb[500005];
bool cmd(ll x,ll y){
	return x<y;
}
bool check(ll x){
	int y=0;
	y=aa[x]-bb[x];
	
	if(y<=b)return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	for(ll i=1;i<=a;i++){
		cin>>aa[i];
	}
	sort(aa+1,aa+a+1,cmd);
	
	for(ll i=1;i<=a;i++){
		bb[i]=bb[i-1]+aa[i];
		aa[i]=aa[i]*i;
	}
	ll l=1,r=a,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			while(aa[mid+1]==aa[mid])mid++;
			ans=mid;
			
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//5 5
//1 2 4 8 9

//5 8
//-3 -1 2 2 7

