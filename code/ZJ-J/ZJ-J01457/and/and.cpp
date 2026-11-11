//??:?? 9:45
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,ans,ct;
int a[maxn];
int cnt[50];
int d[maxn][50];
int check[maxn];
bool duck(int x){
	int cn=0;
	for(int i=1;i<=n;i++){
		if(!check[i]) continue;
		if(d[i][x]) cn++;
	}
	return cn>=m;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;ct=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int temp=a[i];
		for(int j=0;j<=50;j++){
			if(!temp) break;
			if(temp&1) cnt[j]++,d[i][j]=1;
			temp=temp>>1;
		}
		check[i]=1;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=30;j>=0;j--){
//			cout<<d[i][j];
//		}
//		puts("");
//	}
	for(int I=31;I>=0;I--){
		if(duck(I)){
			for(int i=1;i<=n;i++){
				if(!check[i]) continue;
				if(!d[i][I]) check[i]=0;
			}
		}
	}
	ans=2147483647;
	for(int i=1;i<=n;i++){
		if(!check[i]) continue;
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
/**
en zhe ti bu hui guo le ba
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
**/
