#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
      long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(a[i]&a[j],ans);
            }
        }
        cout<<ans<<endl;
        return 0;
	}
	if(m==3){
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    ans=max(a[i]&a[j]&a[k],ans);
                }
            }
        }
        cout<<ans<<endl;
        return 0;
	}
	if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++){
            ans=a[i]&ans;
        }
        cout<<ans<<endl;
        return 0;
	}
	return 0;
}
