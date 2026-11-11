#include<bits/stdc++.h>
#define int long long
#define endl "\n" 
using namespace std;
int n,m,a[500005];
void f(int step){
	if(m<0){
		cout<<step-1;
		return;
	}if(m==0){
		cout<<step;
		return;
	}
	m-=step*(a[2]-a[1]);
	f(step+1);
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f(0);
	return 0;
}