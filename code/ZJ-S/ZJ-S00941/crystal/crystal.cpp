//14:42 T1 test ac 

//Luogu 711031
//Welcome to add me awa
//Because I'm afraid of something wrong
//so here's no Chinese
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long zz=1,dqsm=0;
	for(long long r=1;r<=n;r++){
		dqsm+=a[r];
		while(a[r]*(r-zz+1)-dqsm>m)dqsm-=a[zz],zz++;
		ans=max(ans,r-zz+1);
	}
	cout<<ans;
} 
