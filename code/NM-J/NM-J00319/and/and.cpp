#include<bits/stdc++.h>
using namespace std;
long long n,m,q,s[1000086],ans=0;
string a;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
    	cin>>s[i];
	}
	if(q==2){
		for(int i=1;i<n;i++){
			ans=max(ans,s[i]&s[i+1]);
		}

	}
	else if(q==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,s[i]);
		}
	}
	else ans=0;
	cout<<ans;
    return 0;
}
