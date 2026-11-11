#include <bits/stdc++.h>
using namespace std;
inline int calc1(int n){
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=(bool)(1<<(i-1));
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200006],ans=-2147483648,temp=2147483647;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        for(int i=1;i<(1<<n);i++){
            if(calc1(i)==m ){
                temp=2147483647;
                for(int i2=1;i2<=n;i2++){
                    if(i&(1<<(i2-1))){
                        temp&=a[i];
                    }
                }
                if(temp>ans){
                    ans=temp;
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            if(a[i]>=ans){
                ans=a[i];
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            temp=temp&a[i];
        }
        cout<<temp;
        return 0;
    }
    if(m==2){
        int m_pos,n_pos;
        for(n_pos=1;n_pos<=n;n_pos++){
            for(m_pos=n_pos+1;m_pos<=n;m_pos++){
                if(a[m_pos]&a[n_pos]>ans){
                    ans=a[m_pos]&a[n_pos];
                }
            }
        }
        cout<<ans;
        return 0;
    }
    cout<<n-m;
    return 0;
}
