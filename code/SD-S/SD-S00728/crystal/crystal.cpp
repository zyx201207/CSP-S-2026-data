//75pt  
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll m,a[N];
bool f=true; //是否性质
int n;
ll ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			f=false;
		}
	}
	sort(a+1,a+n+1);
	if(f){
		ans=1;
		ll t=a[2]-a[1]; //差值 
		for(int i=1;i<n;i++){
			if(i*(i+1)*t/2<=m) ans++;
			else break;
		}
		cout<<ans;
		return 0;
	} 
	for(int i=1;i<=n;i++){ //枚举最大能量值 
		ll res=1,all=m;
		for(int j=i-1;j>=1;j--){
			ll dif=a[i]-a[j];
			if(dif<=all){
				res+=1;
				all-=dif;
			}else{
				break;
			}
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
} 
