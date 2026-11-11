#include<bits/stdc++.h>
#define maxn 500005
#define ll long long
using namespace std;
ll n,m,a[maxn],ans=0,d;
bool cmp(int x,int y){
	return x>y;
}
int f(int k,int sum){
	if(sum>=m)return k-1;
	return f(k+d,sum+k+d);
} 
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal3.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){		
		sort(a+1,a+n+1,cmp);
		ll flag,spend,cnt;
		for(int i=1;i<=n;++i){
			flag=a[i];spend=0;cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]>flag)continue;
				spend+=flag-a[i];cnt++;
				if(spend==m){ans=max(ans,cnt);break;}
				if(spend>m){ans=max(ans,cnt-1);break;}
			}
		} 
		cout<<ans;
		return 0;
	}
	else{
		int d=a[2]-a[1];
		cout<<f(0,0)+1;return 0;
	}
}
