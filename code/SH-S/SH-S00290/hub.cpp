#include<bits/stdc++.h> 
using namespace
const int MAXN=100005;
int a [MAXN];
int main(){
	freopen("crystal.in","r",sidin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	int ans=o;
	for(int i=1;i<=n;++i){
		if(i%k==0||i%10==k){
			ans+=i;
		}
	}
	cout<<ans<<endl;
	
	
	
	
	
	
	
	return 0;
}





