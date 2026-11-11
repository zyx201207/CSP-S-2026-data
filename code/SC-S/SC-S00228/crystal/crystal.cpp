#include<bits/stdc++.h>
#define gbtbl ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define it long long
#define C cin
#define CC cout
#define ru >>
#define chu <<
#define cit const it
#define rt return
#define xiao_deng <=
#define da_deng >=
#define xiaoyu <
#define dayu >
#define rg if
#define fz else
using namespace std;
cit N=5e5+5;

it n,m;
it a[N]; 
it pre[N],t[N];

int main(){
	gbtbl
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	C ru n ru m;
	for(it i=1;i xiao_deng n;i++){
		C ru a[i];
	}
	sort(a+1,a+1+n);
	map<it,it>mp;
	it cnt=0;
	for(it i=1;i xiao_deng n;i++){
		mp[a[i]]++;
	}
	for(it i=1;i xiao_deng n;i++){
		rg(a[i]!=a[i-1]){
			cnt++;
			pre[cnt]=pre[cnt-1]+mp[a[i]];
		}
		t[cnt]=a[i];
	}
//	for(it i=1;i xiao_deng cnt;i++){
//		CC chu pre[i] chu ' ' chu mp[t[i]] chu ' ' chu t[i];
//		CC chu "\n";
//	}
	it mx=0;
	for(it i=1;i xiao_deng cnt;i++){
		mx=max(mx,pre[i]-pre[i-1]);
	}
	it ans=0;
	it sum=0;
	for(it l=1,r=1;r xiao_deng cnt;){
		rg(sum xiao_deng m){
			r++;
			rg(r dayu cnt){
				break;
			}
			sum+=(pre[r-1]-pre[l-1])*(t[r]-t[r-1]);
			rg(sum dayu m){
				ans=max(ans,pre[r-1]-pre[l-1]);
			}fz{
				ans=max(ans,pre[r]-pre[l-1]);
			}
		}fz{
			sum-=(pre[l]-pre[l-1])*(t[r]-t[l]);
			l++;
		}
	}
	CC chu max(mx,ans);
	
	rt 0;
}


/*
8 10
1 1 2 2 3 3 4 7
*/














