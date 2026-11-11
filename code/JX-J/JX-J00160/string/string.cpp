#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a[200001]={};
    char c[200001]={};
    long long n,l,r,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    l=1;
    r=n;
    while(1){
        if(r==l){
            cout<<ans;
            break;
        }
        if(c[l]!=c[r]){
            if(a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                r--;
                //cout<<l<<r<<" ";
            }
            else if(a[l]<a[r]){
                ans+=a[l];
                a[r]-=a[l];
                l++;
                //cout<<l<<r<<" ";
            }
            else{
                ans+=a[l];
                if(r-1==l){
                    cout<<ans;
                    break;
                }
                r--;
                l++;
            }
        }
        else{
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }
            else if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }
            else{
                if(r-1==l){
                    cout<<ans;
                    break;
                }
                r--;
                l++;
            }
        }
    }
    /*long long n,q=0,x,ans=0;
    string s,c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        q+=x;
        for(int j=1;j<=x;j++){
            s+=c;
        }
    }
    if(q%2!=0){
        int l=q/2,r=q/2;
        while(1){
            if(l==0 and r==s.size()-1){
                cout<<ans;
                break;
            }
            l--;
            r++;
            if(s[l]!=s[r]){
                ans++;
            }
        }
    }
    else{
        int l=q/2-1,r=q/2;
        while(1){
            if(l==0 and r==s.size()-1){
                cout<<ans;
                break;
            }
            if(s[l]!=s[r]){
                ans++;
            }
            l--;
            r++;
        }
    }*/
    return 0;
}

