#include<bits/stdc++.h>
using namespace std;
long long minn,b[1000001],t,k,mx,mxx,n,s,a[1000001],ans[1000001],m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdin);
    f=true;
    long long mi=3102400,mii=3102400;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    if(m==0){
        for(long long i=1;i<=n;i++){
            ans[a[i]]++;
            if(ans[a[i]]>mx){
                mx=ans[a[i]];
                mxx=i;
            }
        }
        cout<<mx;
    }
    else{
        for(long long i=1;i<=n;i++){
            ans[a[i]]++;
            if(a[a[i]]>mx){
                mx=a[a[i]];
            }
            if(a[a[i]]<mi){
                mx=a[a[i]];
            }
        }
        for(long long i=mi;i<=mx;i++){
            if(ans[i]!=0){
                t=m;
                for(int j=i;i>=mi;i++){
                    for(int k=1;k<=n;k++){
                        a[k]=b[k];
                    }
                    if(ans[j]!=0){
                        t--;
                        ans[j]--;
                        ans[j+1]++;
                        if(t==0){
                            continue;
                        }
                    }
                }

                if(ans[i]>mii){
                    mii=ans[i];
                }
            }
        }
    }

    return 0;
}
