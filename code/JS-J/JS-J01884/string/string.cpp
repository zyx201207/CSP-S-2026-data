#include<bits/stdc++.h>
using namespace std;
int n,x,ans;
string str;
struct node{
    int len;
    char a;
}a[200005];
int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].a;
        for(int j=1;j<=a[i].len;j++) str+=a[i].a;
    }

    int len=str.size(),l,r;
    str=' '+str;
    if(len%2==0) {
        l=len/2,r=len/2+1;
    }
    else l=len/2,r=len/2+2;
    //for(int i=0;i<=len;i++){
     //   cout<<str[i];
    //}
   // cout<<endl;
    while(l>0&&r<=len){
        if(str[l]!=str[r]) ans++;
        l--,r++;
    }
    cout<<ans;
    return 0;
}
//24104423
