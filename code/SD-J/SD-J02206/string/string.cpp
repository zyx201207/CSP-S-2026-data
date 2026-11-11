#include<bits/stdc++.h>
using namespace std;
int n,jishu=1;
long long cinalong=0,ans=0,linlong=0,qianzhuihe[200005];
string cina="",lincin;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=1;i<=n;i++){
		cin>>linlong>>lincin;
		for(int j=1;j<=linlong;j++){
			cina+=lincin;
		}
		cinalong+=linlong;
	}
	for(long long i=0,j=cinalong-1;i<=j;i++,j--){
		if(cina[i]!=cina[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
