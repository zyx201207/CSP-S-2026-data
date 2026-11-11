#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
string change(ll x){
    string ch,ansch;
    while(x){
        ch+=char((x%2)+'0');
        x/=2;
    }
    for(int i=ch.size()-1;i>=0;i--){
        ansch+=ch[i];
    }
    return ansch;
}
string buchong(string x,int mx){
    string ans;
    for(int i=0;i<mx-x.size();i++){
        ans+='0';
    }
    return ans+x;
}
ll ad(ll a,ll b){
    string ans;
    string a_2=change(a),b_2=change(b);
    if(a_2.size()!=b_2.size()){
        int mx=max(a_2.size(),b_2.size());
        if(a_2.size()>b_2.size()){
            b_2=buchong(b_2,mx);
        }else{
            a_2=buchong(a_2,mx);
        }
    }
    for(int i=0;i<a_2.size();i++){
        ans+=char((int(a_2[i]-'0')&&int(b_2[i]-'0'))+'0');
    }
    ll ans_num=0,t=1;
    for(int i=ans.size()-1;i>=0;i--){
        ans_num+=int(ans[i]-'0')*t;
        t*=2;
    }
    return ans_num;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<a[0];
        return 0;
    }else if(n==2){
        if(m==1){
            cout<<max(a[0],a[1]);
            return 0;
        }else{
            cout<<ad(a[0],a[1]);
            return 0;
        }
    }
    if(m==1){
        ll mx=0;
        for(int i=0;i<n;i++){
            mx=max(a[i],mx);
        }
        cout<<mx;
        return 0;
    }
    if(m==2){
        ll mx=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mx=max(mx,ad(a[i],a[j]));
            }
        }
        cout<<mx;
        return 0;
    }
    if(m==3){
        ll mx=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                   mx=max(mx,ad(ad(a[i],a[j]),a[k]));
                }
            }
        }
        cout<<mx;
        return 0;
    }
    if(m==4){
        ll mx=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int z=k+1;z<n;z++){
                         mx=max(mx,ad(ad(ad(a[i],a[j]),a[k]),a[z]));
                    }
                }
            }
        }
        cout<<mx;
        return 0;
    }
    if(m==5){
        ll mx=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int z=k+1;z<n;z++){
                         for(int q=z+1;q<n;q++){
                            mx=max(mx,ad(ad(ad(ad(a[i],a[j]),a[k]),a[z]),a[q]));
                         }
                    }
                }
            }
        }
        cout<<mx;
        return 0;
    }
    if(m==n){
        ll ans=ad(a[0],a[1]);
        for(int i=2;i<n;i++){
            ans=ad(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
