#include<iostream>
#include<cstring>
using namespace std;
string s;
string t;
long long ans;
void f(int l,int r){
    if(l>=r)return;
    int mid=l+r>>1;
    ans=mid;
    f(l,mid);
    f(mid+1,r);
    int i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(s[i]!=s[j]){
            t+=s[i++];
        }
        else{
            t+=s[j++];
        }
    }
    while(i<=mid){
        t+=s[i++];
    }
    while(j<=r){
        t+=s[j++];
    }
    for(int k=0,i=l;i<=r;k++,i++){
        if(s[i]!=t[k])
        ans++;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        string t;
        cin>>x>>t;
        for(int j=1;j<=x;j++){
            s+=t;
        }
    }
    f(1,n);
    cout<<ans;
    return 0;
}
