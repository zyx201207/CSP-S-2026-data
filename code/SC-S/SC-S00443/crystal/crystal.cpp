//crystal
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ull MAXN=1000005;
ull n,sum=0;
ll a[MAXN],pre[MAXN],m,cnt;
bool f=0;

bool rule(ll a,ll b){
	return a<b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
//	sort(a+0,a+n+1,rule);
	//前缀差 
	pre[0]=0;
	for(int i=1;i<n;i++) pre[i]=a[i]-a[i-1];
	for(int i=0;i<n;i++){
		ll temp=m;
		cnt+=a[i];
//		cout<<cnt<<" ";
		temp-=pre[i];
		if(temp>=0&&cnt<=m) sum++;
		else break;
	}
	cout<<sum; 
	return 0;
}