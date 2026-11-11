#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll C,T,n,d,a[N];
ll mp[N];
void solve1(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll k=i,sum=0;
		for(int j=i;j<n;j=k){
			while(k+1<=n&&a[k+1]-a[j]<=d){
				k++;
				ll s2=sum;
				if(j>i&&a[k]-a[j-1]<=d){
					s2++;
				}if(j>i+1&&a[k]-a[j-2]<=d){
					s2++;
				}if(s2==1){
					ans++;
				}
			}if(k==j){
				break;
			}
			if(j>i&&a[k]-a[j-1]<=d){
				sum++;
			}if(j>i+1&&a[k]-a[j-2]<=d){
				sum++;
			}
			if(sum>=2){
				break;
			}
		}
	}cout<<ans<<"\n";
}
void solve2(){
	if(n<=3){
		cout<<"0\n";
		return ;
	}
	ll cz=a[2]-a[1];
	if(cz==0){
		cout<<"0\n";
		return ;
	}
	if(d/cz<=1||n<=(d/cz*2-1)){
		cout<<"0\n";
		return ;
	}cout<<n-(d/cz*2-1)<<"\n";
	return ;
}
void solve3(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(i<=n-3){
			ll p=upper_bound(a+1+i,a+1+n,a[i]+d)-a-1;
			if(p!=i+1){
				mp[p]++;
			}
		}if(i>3){
			ll p=lower_bound(a+1,a+i,a[i]-d)-a;
			if(p!=i-1){
				ans+=mp[p+1];
			}
		}
	}cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mp[i]=0;
		}
		if(C==13||C==14){
			solve3();
		}else if(C==11||C==12){
			solve2();
		}else{
			solve1();
		}
	}
	return 0;
}