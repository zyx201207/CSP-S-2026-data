#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;
ll m,a[N],num[N],num_[N];
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int flg;
    cin>>n>>m;
    int g=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
		if(a[i]-a[i-1]!=a[i-1]-a[i-2] && i>2){
			flg=0;
		}
		if(a[i]!=a[i-1]){
			num[g++]=i-1;
		}
	}
	num[g]=n;
//	for(int i=1;i<=g;i++){
//		cout<<num[i]<<' ';
//	}
	//cout<<flg[0]<<flg[1]<<flg[2];
	if(flg){
		//sub 13-18
		int d=a[2]-a[1];
		int x=floor((double)((-1.0+sqrt(1.0+8.0*(double)m/(double)d))/2.0));
		ans=min(x+1,n);
		cout<<ans;
	}else{
		//sub 1-9
		sort(a+1,a+1+n);
		ll maxcnt=-1e18;
		for(int i=1;i<=g;i++){
			ll cnt=0;
			int lst=num[i];
			ll sum=0;
			for(int j=lst;j>=1;j--){
				sum+=a[lst]-a[j];
				if(sum>m){
					break;
				}else{
					++cnt;
				}
			}
			maxcnt=max(maxcnt,cnt);
		}
		cout<<maxcnt;
	}
	//¸ÐÐ»ccfÂèÂè £¬½ñÄêÎÒÐ´ÌØÅÐT1Ó¦¸ÃÄÜÄÃ75£¬Ð»Ð»ccfÂèÂè£¡£¡£¡mua£¡£¡£¡ 
    return 0;
}
