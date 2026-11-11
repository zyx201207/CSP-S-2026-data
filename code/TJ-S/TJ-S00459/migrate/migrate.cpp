#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,d;
const int N=2e6;
ll a[N];
ll cha;
void A(){
	d/=cha;
//	cout<<d<<' '<<cha<<' ';
	if(d==1&&cha>1){
		cout<<"0\n";
		return;
	}
	if(d==0){
		cout<<"0\n";
		return;
	}
	if(d>n/2){
		cout<<0<<'\n';
	}else{
		cout<<n-d*2+1<<'\n';
	}
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c;
	ll t;
	scanf("%d %lld",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&d); 
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			cha=a[i]-a[i-1];
		} 
		if(d==1&&cha>1){
			cout<<"0\n";
			continue;
		}
		if(c==11||c==12){
			A();
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

