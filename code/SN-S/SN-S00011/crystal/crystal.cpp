#include<bits/stdc++.h>
using namespace std;
long long cry[500010];
long long dif[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>cry[i];
	}
	sort(cry+1,cry+n);
	for(long long j=1;j<=n-1;j++){
		dif[j]=cry[j+1]-cry[j]; 
	}
	long long cnt=1;
	for(long long k=1;k<=n-1;k++){
		if(m>=dif[k]*k){
			cnt++;
			m-=dif[k]*k;
		}else{
			cout<<cnt;
			break;
		}
	}
	return 0;
} 
