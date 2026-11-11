#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
int n;
ll m;
int v[N];
int ans=0;
void f(int x){
	ll l=m;
	if(l<0)return;
	if(x<0){
		return;
	}else{
		int sum=0;
		int temp=0;
		for(int j=1;j<=x;j++){
			sum=v[x]-v[j];
			if(sum>l){
				continue;
			}else{
				l=l-sum;
				temp++;
			}
		}
		ans=max(temp,ans);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>v[i];
	}
	sort(v+1,v+n+1);
	for(int i=1;i<=n;i++){
		f(i);
	}
	cout<<ans;
	return 0;
}
