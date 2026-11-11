#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long x[200005];
	char k[200005];
	long long ans=0;
	for(int i=1;i<=n;i++){
        cin>>x[i]>>k[i];
	}
	for(int i=1;i<=n;i++){
        cout<<k[i]<<" ";
	}
	int l=1,r=n;
	while(l<r){
        int t=min(x[l],x[r]);
        if(k[l]!=k[r]){
            ans+=t;
            x[r]-=t;
            x[l]-=t;
        }
        else{
            x[r]-=t;
            x[l]-=t;
        }
        if(x[l]==0) l++;
        if(x[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
