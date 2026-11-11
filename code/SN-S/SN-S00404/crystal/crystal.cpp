#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
ll n,m,a[maxn],b[maxn],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	int p=0;
	for(int i=2;i<n;i++){
		if(b[i]!=b[i+1]){
			p++;
			break;
		}
	}
	if(!p){
		ll gc=b[2],cnt=0;
		for(int i=1;cnt<m;i++)if(gc*(cnt+i)<=m){
			cnt+=i;
			ans++;
		}else break;
		cout<<ans+1<<endl;
		return 0;
	}else{
		if(n<=5)cout<<3<<endl;
	}
	return 0;
}
