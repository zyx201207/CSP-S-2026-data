#include<bits/stdc++.h>
using namespace std;
struct node{
    int a;
    char b;
}s[200009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].b;
    }
    long long ans=0;
    int l=1,r=n;
    while(l<r){
        if(s[l].a<=s[r].a){
            if(s[l].b!=s[r].b)ans+=s[l].a;
            s[r].a-=s[l].a;
            l++;
        }else if(s[r].a<s[l].a){
            if(s[l].b!=s[r].b)ans+=s[r].a;
            s[l].a-=s[r].a;
            r--;
        }

    }
    cout<<ans;
    return 0;
}
