#include <bits/stdc++.h>
using namespace std;
int n,m;
long long maxx;
long long s=pow(2,31)-1;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(m==1){
       cout<<maxx;
       return 0;
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            s&=a[i];
        }
        cout<<s;
        return 0;
    }
    if(m==2){
            long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                long long q=a[i]&a[j];
                ans=max(ans,q);
            }
        }
    cout<<ans;
    return 0;
    }
    if(maxx<=4){
        int w1,w2,w3,w4;
        for(int i=1;i<=n;i++){
            if(a[i]==2){
                w2++;
            }
            if(a[i]==3){
                w3++;
            }
            if(a[i]==1){
                w1++;
            }
            if(a[i]==4){
                w4++;
            }
        }
        if(w4>=m){
            cout<<"4";
            return 0;
        }
        if(w3>=m){
            cout<<"3";
            return 0;
        }
        if(w2+w4>=m){
                cout<<"2";
            return 0;
        }
        if(w1+w3>=m){
            cout<<"1";
        return 0;
        }
        cout<<"0";
        return 0;
    }
    sort(a+1,a+n+1);
    long long q=pow(2,31)-1;
    for(int i=n;i>=n-m+1;i--){
        q&=a[i];
    }
    cout<<q;
    return 0;

}
