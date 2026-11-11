#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long b[200010];
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans=max(ans,a[i]);
    }
    if(m==1){
        cout<<ans<<endl;
        return 0;
    }
    ans=(a[1])&(a[2]);
    if(m==n){
        for(int i=3;i<=n;i++){
            ans=((ans)&&(a[i]));
        }
        cout<<ans<<endl;
        return 0;
    }
    ans=0;
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,((a[i])&(a[j])));
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    ans=0;
    for(int i=1;i<=(1<<n);i++){
        int t=i;
        int k=i;
        long long num1=0;
        while(t){
            int s=t%2;
            if(s==1){
                num1++;
            }
            t/=2;
        }
        int p=0,q=1;
        if(num1==m){
            while(k){
                int s=k%2;
                if(s==1){
                    p++;
                    b[p]=a[q];
                }
                q++;
                k/=2;
            }
        }
        long long s=(b[1])&(b[2]);
        for(int j=3;j<=p;j++){
            s=((s)&(b[j]));
        }
        ans=max(ans,s);
    }
    cout<<ans<<endl;
    return 0;
}

