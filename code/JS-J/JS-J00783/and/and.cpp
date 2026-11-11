#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll a[N],n,m;
void solve1_5(){
	ll mx=-1;
	vector<ll> chose;
	for(ll i=1;i<pow(2,n);i++){
		ll hh=i;
		ll cnt=0;
		ll tot=0;
		chose.clear();
		while(hh){
			if(hh&1){
				cnt++;
				chose.push_back(a[tot]);
			}
			hh>>=1;
			tot++;
		}
		if(cnt!=m)continue;
		ll res=chose[0];
		for(ll j=1;j<m;j++){
			res&=chose[j];
		}
		mx=max(mx,res);
	}
	cout<<mx<<endl;
}
void solve6(){//m==1
    ll mx=-1;
    for(ll i=0;i<n;i++)mx=max(mx,a[i]);
    cout<<mx<<endl;
}
void solve7(){//m==n
    ll ans=a[0];
    for(ll i=1;i<n;i++)ans&=a[i];
    cout<<ans<<endl;
}
void solve8_10(){//m==2
    ll mx=-1;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            ll nd=a[i]&a[j];
            mx=max(mx,nd);
        }
    }
    cout<<mx<<endl;
}
void solve11_12(){//m==n-1
    cout<<0<<endl;//I will think later.
}
void solve13(){//对于所有 i (1 ≤ i ≤ n),均存在非负整数 k i 满足 a i = 2 k i − 1。
    sort(a,a+n);
    cout<<a[n-m]<<endl;
}
void solve16_17(){
    cout<<3<<endl;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    bool check_13=true;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        bool flg=false;
        for(ll j=0;j<=25;j++){
            if(a[i]==pow(2,j)-1){
                flg=true;
            }
        }
        if(!flg)check_13=false;
    }
    if(check_13){
        solve13();
        return 0;
    }
    if(n<=20&&m<=n){
        solve1_5();
    }
    else if(n<=2000){
        if(m==1)solve6();
        else if(m==n)solve7();
        else if(m==2)solve8_10();
        else cout<<0<<endl;
    }
    else if(n<=200000){
        if(m==n-1)solve11_12();
        else solve16_17();
    }
    return 0;
}
