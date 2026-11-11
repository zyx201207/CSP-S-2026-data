#include<bits/stdc++.h>
using namespace std;
long long n,len,cntx,cnty;
struct node{
    int a;
    char c;
}s[200005];
vector<node> x,y;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
        len+=s[i].a;
    }
    long long hlen=(len+1)/2,ans=0,sum=0;
    for(int i=1,j=n;i<=n&&j>=1&&i<=j&&sum<hlen;){
        if(s[i].a==s[j].a){
            if(s[i].c!=s[j].c){ans+=s[i].a;i++;j--;}
            else {i++;j--;}
            sum+=s[i].a;
        }
        else if(s[i].a>s[j].a){
            if(s[i].c!=s[j].c){ans+=s[j].a;s[i].a-=s[j].a;j--;}
            else{s[i].a-=s[j].a;j--;}
            sum+=s[j].a;
        }
        else{
            if(s[i].c!=s[j].c){ans+=s[i].a;s[j].a-=s[i].a;i++;}
            else{s[j].a-=s[i].a;i++;}
            sum+=s[i].a;
        }
    }
    cout<<ans;
    return 0;
}
