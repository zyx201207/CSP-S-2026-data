#include<bits/stdc++.h>
using namespace std;
long long a[500006],ans=0;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
//别忘记取消！！
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
long long n,m;
cin>>n>>m;
for(long long i=1;i<=n;i++){
	cin>>a[i];}
sort(a+1,a+1+n);
long long mid=a[n/2];
long long b[500006];
for(long long i=1;i<=n;i++){
	b[i]=abs(mid-a[i]);
	}
sort(b+1,b+1+n);
for(long long i=1;i<=n;i++){
	m-=b[i];
	if(m>=0){
		ans++;	
	}
	else break;
	}
	cout<<ans;
return 0;
}
