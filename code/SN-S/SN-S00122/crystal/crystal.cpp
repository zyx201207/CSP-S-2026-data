#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500001];
int s[500001];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>5000){
		int d=a[2]-a[1];
		for(int i=2;i<=n;i++){
			if(i*(i-1)*d/2>m){
				cout<<i-1;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		int l=1,r=i;
		while(r<=n){
			if(a[r]*i-(s[r]-s[l-1])<=m){
				cout<<i;
				return 0;
			}
			else{
				l++;
				r++;
			}
		}
	}
	return 0;
}
//T1 ~75pts
/*
I've read T2 and think it's much more difficult than T1. Can I get some points in T2?
Oh Arknights is so much fun I can't hold on anymore.
YeBaiowo is so cute nya~
luogu UID 1327996 follow me pls!
guan zhu yebai miao! guan zhu yebai xie xie miao!
well... I can't get blue tick this year. 
*/
