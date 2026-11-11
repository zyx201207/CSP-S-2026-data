#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],l,r,ans,tmp;
bool check(long long x){
	long long sum=0;
	for(int i=1;i<=n;i++){
		if((a[i]&x)==x)sum++;
	}
	if(sum>=m)return 1;
	else return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		long long guess=tmp|(1<<i);
		if(check(guess)){
			tmp|=(1<<i);
			ans=tmp;
		}
	}
	cout<<ans;
	return 0;
}
