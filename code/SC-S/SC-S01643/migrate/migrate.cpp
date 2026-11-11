#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d,cnt=0,min_n=1e9;
int a[2000005],ans1[100005];
void fd(int st,int ed,int lens){
	if(st==ed){
		if(min_n==lens){
			cnt++;
		}if(min_n>lens){
			min_n=lens;
			cnt=1;
		}return;
	}
	for(int i=st+1;i<=ed;i++){
		if((a[i]-a[st])<=d) fd(i,ed,lens+1);
	}
}
bool fd_rd(int st,int ed){
	cnt=0;
	min_n=1e9;
	fd(st,ed,0);
	if(cnt==2) return 1;
	else return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				if(fd_rd(i,j)){
					ans++;
				}
			}
		}ans1[k]=ans;
	}for(int i=1;i<=t;i++) cout<<ans1[i]<<"\n";
	return 0;
}