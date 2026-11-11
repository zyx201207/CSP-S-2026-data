#include<bits/stdc++.h> 
using namespace std;
int a[500003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<n;
		return 0;
	}
	int cnt=1,ans=1;
	if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]) cnt++;
			else ans++;
		}
		cout<<cnt<<" "<<ans;
		return 0;
	}
	while(n--){
		cout<<0<<" ";
	}
	return 0;	
}
