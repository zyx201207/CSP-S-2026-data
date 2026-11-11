#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pi pair
#define ull unsigned long long
#define endl "\n"
using namespace std;
const int N=5e5+100;
int ans=1;
const ll INF=1e12;
ll a[N];
ll n,m;
ll _abs(ll a){
	if(a<0){
		return -a;
	}return a;
}
bool check(ll x){
	int cnt=0;ll num=0;
	bool flag=1;//m
	auto p=lower_bound(a+1,a+1+n,x)-a;
	p=min(p,n);
	while(a[p]==x){
		p++;
	}
	p=min(p,n);
	while(a[p]>x&&p>1){
		p--;
	}
	while(num<=m){
		if((ll)(num+(ll)(x-a[p]))>m){
			flag=0;
			break;
		}
		else{
			cnt++;
			num=num+(x-a[p]);
			p--;
			if(p==0){
				flag=1;
				break;
			}
		}
	}
	ans=max(ans,cnt);
	return flag;
}
void solve1(){
	for(int i=n;i>=1;i--){
		ll ans=(a[i-1]+1)*(i-1)/2;
		if(ans<=m){
			cout<<i<<endl;
			return;
		}
	}cout<<1<<endl;
	return;
}
void solve2(){
	for(int i=n;i>=1;i--){
		ll ans=(a[i-1]+a[1])*(i-1)/2;
		if(ans<=m){
			cout<<i<<endl;
			return;
		}
	}cout<<1<<endl;
	return;
}
int main(){
//	system("fc crystal.ans crystal.out");
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>a[1];
    if(n==1){
    	cout<<1;
    	return 0;
	}
    bool flag=1,flag1=1;
    cin>>a[2];
    if(a[1]!=1||a[2]!=2){
    	flag=0;
	}ll t=a[2]-a[1];
    for(int i=3;i<=n;i++){
    	cin>>a[i];
    	if(a[i]!=i){
    		flag=0;
		}
		if((a[i]-a[i-1])!=t){
			flag1=0;
		}
	}
	if(flag){
		solve1();
		return 0;
	}
	else if(flag1){
		solve2();
		return 0;
	}
	sort(a+1,a+1+n);
	ll l=a[1],r=m+a[n];
    if(_abs(a[1])<=100&&_abs(a[n])<=100){	 
    	for(int i=a[1];i<=a[n];i++){
		    check(i);
	    } 
	    cout<<ans;
	    return 0;
	}
	while(l<r){
		ll mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	cout<<ans;
	return 0;
}

