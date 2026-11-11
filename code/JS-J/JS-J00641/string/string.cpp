#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct str{
    long long a;
    char c;
}in[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>in[i].a>>in[i].c;
    }
    for(int i=1;i<=n;i++){
        while(in[i].a-in[n].a>0){
            if(in[n].c!=in[i].c){
                ans=ans+in[n].a;
            }
            in[i].a=in[i].a-in[n].a;
            in[n].a=0;
            n--;
        }
        if(in[n].c!=in[i].c){
            ans=ans+in[i].a;
        }
        in[n].a=in[n].a-in[i].a;
        in[i].a=0;
    }
    cout<<ans;
    return 0;
}
