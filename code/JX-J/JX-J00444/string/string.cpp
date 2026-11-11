#include <bits/stdc++.h>
using namespace std;

long long n,ans,len;

struct Node{
    int a;
    char c;
}s[2000010];
void print(){
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<s[i].a<<" "<<s[i].c<<" ";
        cout<<ans<<endl;
    }
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
        len+=s[i].a;
    }
    len/=2;
    int p=n;
    int b=1;

    while(p>b){
        while(s[b].a!=0){
            if(s[b].a<=s[p].a){
                if(s[b].c != s[p].c){
                    ans+=s[p].a;
                }
                s[p].a-=s[b].a;
                s[b].a=0;
                if(s[p].a==0) p--;
            }else{
                if(s[b].c != s[p].c){
                    ans+=s[p].a;
                }
                s[b].a-=s[p].a;
                s[p].a=0;
                p--;
            }

        }
        b++;
    }
    if(len<=ans) cout<<len;
    else cout<<ans;
    return 0;
}
