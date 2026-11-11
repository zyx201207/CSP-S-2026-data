#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
ll n,m,b,k,get,ans,a[maxn];
ll has[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
		freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k=0,b=a[i];
		while(b){
			if(b&1) has[k]++;
			b>>=1;
			k++;
		}
		k--;	
	}
	sort(a+1,a+n+1,cmp);
	k=0,b=a[1];
	while(b){
		b>>=1;
		k++;
	}
	k--;
//	for(int i=k;i>=0;i--) cout<<has[i]<<' ';
	for(int i=k;i>=0;i--){
		if(has[k]>=m){
			get=k;
		}
	}
	int m1=0;
//	cout<<get<<endl;
	k++;
	ans=(1<<k)-1;
	for(int i=1;i<=n;i++){
		if(m1==m) break;
		if((a[i]>>get)&1){
			ans&=a[i],m1++;
//			cout<<a[i]<<' ';
		}
	} 
	cout<<ans;
	return 0;
}
