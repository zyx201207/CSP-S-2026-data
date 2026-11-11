#include<iostream>
#include<cstdio>
#include<cmath>
//#define int long long
//#define const 998244353
using namespace std;
int c1,c2,s1,s2,ans[4];char u,v; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>u>>c2>>s2>>v;
	if(c1==c2){
		ans[0]=1;
		if(s1==s2){
			ans[1]=1;
			if((u>'C'&&v>'C')||(u<'D'&&v<'D')){
				ans[2]=1;
				if(u=='D')u='E';
				if(v=='D')v='E';
				if(abs(u-v)==1)ans[3]=1;
			}
		}
	}
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	return 0;
}
