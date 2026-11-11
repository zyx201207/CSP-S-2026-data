#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long cnt=0;
	long long last;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		if(i==2){
			cnt=a-last;
		}
		last=a;
	}
	int ans=0;
	long long k=cnt;
	for(int i=1;i<=n;i++){
		if(m>=cnt){
			ans++;
			m-=cnt;
			cnt+=k;
		}
	}
	cout<<ans+1<<endl;
	return 0;
}
