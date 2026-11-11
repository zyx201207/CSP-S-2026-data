#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m/*,a[500006],dp[500006]*/;
struct crystal{
	int num,cha;
}a[500006];
bool cmp(crystal x,crystal y){
	return x.cha<y.cha;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int zt=1,zt2=1,gong_cha=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		if(a[i].num!=i) zt=0;
		if(i==2) gong_cha=a[2].num-a[1].num;
		else if(i>2){
			if(a[i].num-a[i-1].num!=gong_cha) zt2=0;
		}
	}
	int mx=1;
	if(zt){
		int mx=1;
		for(int i=2;i<=n;i++){
			if((1+i)*1.0/2*i-i>m) break;
			mx++;
		}
		cout<<mx;
		return 0;
	}
	else if(zt2){
		int mx=1;
		for(int i=2;i<=n;i++){
			if((gong_cha+gong_cha*(i-1))*(i-1)/2>m) break;
			mx++;
		}
		cout<<mx;
		return 0;
	}
	else if(n<=20){
		for(int k=-30;k<=30;k++){
			for(int i=1;i<=n;i++){
				if(a[i].num<=k) a[i].cha=k-a[i].num;
				else a[i].cha=1e9;
			}
			sort(a+1,a+1+n,cmp);
			int cnt=0,js=0;
			for(int i=1;i<=n;i++){
				if(a[i].cha==1e9) break;
				if(a[i].cha>m) break;
				if(cnt<0){
					js=0;
					break;
				}
				cnt+=a[i].cha;
				js++;
			}
			mx=max(mx,js);
		}
	}
	else{
		for(int k=-100;k<=100;k++){
			for(int i=1;i<=n;i++){
				if(a[i].num<=k) a[i].cha=abs(k-a[i].num);
				else a[i].cha=1e9;
			}
			sort(a+1,a+1+n,cmp);
			int cnt=0,js=0;
			for(int i=1;i<=n;i++){
				if(a[i].cha==1e9) break;
				if(a[i].cha>m) break;
				if(cnt<0){
					js=0;
					break;
				}
				cnt+=a[i].cha;
				js++;
			}
			mx=max(mx,js);
		}
	}
	cout<<mx;
	return 0;
}