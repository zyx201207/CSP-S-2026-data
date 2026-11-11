#include<bits/stdc++.h>
using namespace std;
struct Node{
    int i;
    char c;
}a[200009];
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long num=0,l=0,r=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].i>>a[i].c;
        num+=a[i].i;
    }
    int i=0,j=n+1;
    while(l<num/2 && r<num/2){
        if(l<r){
            l+=a[++i].i;
            if(a[i].c!=a[j].c){
                if(l>r){
                    ans+=r-l+a[i].i;
                }
                else{
                    ans+=a[i].i;
                }
            }
        }
        if(l>r){
            r+=a[--j].i;
            if(a[i].c!=a[j].c){
                if(l<r){
                    ans+=l-r+a[j].i;
                }
                else{
                    ans+=a[j].i;
                }
            }
        }
        if(l==r){
            r+=a[--j].i,l+=a[++i].i;
            if(a[i].c!=a[j].c) ans+=min(a[i].i,a[j].i);
        }
    }
    cout<<ans;
}
