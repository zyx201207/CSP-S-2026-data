#include<bits/stdc++.h>
using namespace std;
long long n,m,a,nl1[10000];//水晶数，合成次数，能量值

void solve(){
int ans=0;//结果
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>nl1[a];
	a++;//定义水晶能量值
}
for(int j=0;j<=m;j++){//合成
	if(nl1[a]!=nl1[a+1]){
		nl1[a]+1;
	}else ans++;
if(ans%2==0)ans+1;
}
cout<<ans/2;
}
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
freopen("hub.in","r",stdin);
freopen("hub.out","w",stdout);
int t=1;
//cin>>t;
while(t--){
    solve();
}
return 0;
}

