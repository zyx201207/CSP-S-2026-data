#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
        cin>>a[i];
	}
	if(m==2){
        for(long long i=1;i<=n-1;i++){
            for(long long j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    long long s=a[1];
    if(m==n){
        for(int i=2;i<=n;i++){
            s=s&a[i];
        }
        cout<<s;
        return 0;
    }
    if(m==1){
        for(long long i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m==3){
        for(long long i=1;i<=n-2;i++){
            for(long long j=i+1;j<=n-1;j++){
                for(long long k=j+1;k<=n;k++){
                    ans=max(ans,a[i]&a[j]&a[k]);
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==4){
        for(long long i=1;i<=n-3;i++){
            for(long long j=i+1;j<=n-2;j++){
                for(long long k=j+1;k<=n-1;k++){
                    for(long long l=k+1;l<=n;l++){
                        ans=max(ans,a[i]&a[j]&a[k]&a[l]);
                    }

                }
            }
        }
        cout<<ans;
        return 0;
    }
}
