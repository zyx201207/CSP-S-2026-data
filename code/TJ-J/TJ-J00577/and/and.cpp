#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
string s[N];
ll a[N];
ll n,m;
bool ljx(int x){
	for(int i=0;i<=x;i++){
		if(pow(2,i)==x)return 1;
	}
	return 0;
}
void A(){
		ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
//		while(k){
//			a[i]+=k%2;
//			a/=2;
//		}
//		revrese(a[i].begin(),a[i].end());
	}
}
void AB(){
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
}
int main(){;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	bool flag1,flag2;
	flag1=flag2=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=i-1)flag1=0/*,cout<<"1:"<<a[i]<<' '*/;
		if(ljx(a[i]+1)==0)flag2=0/*,cout<<"2:"<<a[i]<<' '*/;
	}
	if(flag1||flag2){
		AB();
		return 0;
	}
	ll mx=LONG_LONG_MIN+100;
	do{
		
		mx=max(mx,(a[1]&a[2]&a[3]));
	}
	while(next_permutation(a+1,a+n+1));
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
