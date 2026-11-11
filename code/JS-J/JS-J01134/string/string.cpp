#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,num[200005],st[200005],ed[200005];
    char c[200005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i]>>c[i];
    }
    st[1]=1;
    for(int i=2;i<=n+1;i++){
        st[i]=st[i-1]+num[i-1];
    }
    ed[n]=1;
    for(int i=n-1;i>=0;i--){
        ed[i]=ed[i+1]+num[i+1];
    }
    long long l=1,r=n,cnt=0,f=25;
    while(l!=r){ //reminder
        if(c[l]==c[r]){
            if(st[l+1]>ed[r-1]){
                f=1;
                if(ed[r-1]>st[n+1]/2+1){
                    break;
                }
                r--;
            }
            else{
                f=0;
                if(st[l+1]>st[n+1]/2+1){
                    break;
                }
                l++;
            }
        }
        else{
            if(st[l+1]>ed[r-1]){
                if(ed[r-1]>st[n+1]/2+1){
                    break;
                }
                r--;
                if(f==0)
                    cnt+=ed[r]-st[l];
                else
                    cnt+=ed[r]-ed[r+1];
                f=1;
            }
            else{
                if(st[l+1]>st[n+1]/2+1){
                    break;
                }
                l++;
                if(f==1)
                    cnt+=st[l]-ed[r];
                else
                    cnt+=st[l]-st[l-1];
                f=0;
            }
        }
    }
    cout<<cnt;
    return 0;
}
