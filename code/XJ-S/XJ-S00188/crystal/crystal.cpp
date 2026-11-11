#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+5;

ll a[N],ans=-1e9;
ll n,m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool flag=1,flag2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			flag=0;
		}
		if(i>=3 && abs(a[i]-a[i-1])!=abs(a[i-1]-a[i-2])){
			flag2=0;
		}
	}
	//特殊性质A 
	if(flag){
//		cout<<1111;
		int cnt=0,xtp=2;
		while(1){
			if(m<0){
				break;
			}
			m-=xtp;
			xtp+=1;
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	//特殊性质B
	if(flag2){
		int cnt=0,xtp=2,k=abs(a[2]-a[1]);
		while(1){
//			cout<<m<<"\n";
			if(m<0){
				break;
			}
			m-=xtp;
			xtp+=k;
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	sort(a+1,a+1+n);
	if(m<=0){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		cin>>m;
	}
	for(int i=1;i<=n;i++){
		ll t=m,cnt=0;
		for(int j=i;j>=1;j--){
			if(t-abs(a[i]-a[j])>=0){
				t-=abs(a[i]-a[j]);
				cnt++;
			}else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}

