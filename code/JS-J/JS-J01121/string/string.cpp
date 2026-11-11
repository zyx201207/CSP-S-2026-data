#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    int a;
    char c;
};
node t[200007];
long long ans;
main(){
    freopen("string.in","r",stdin);freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i].a>>t[i].c;
    }
    int i=1,j=n;
    while(i<j){
        if(t[i].a>=t[j].a){
            if(t[i].c!=t[j].c){
                ans+=t[j].a;
            }
            t[i].a-=t[j].a;
            t[j].a=0;
        }
        else{
            if(t[i].c!=t[j].c){
                ans+=t[i].a;
            }
            t[j].a-=t[i].a;
            t[i].a=0;
        }
        if(t[i].a==0){i++;}
        if(t[j].a==0){j--;}
    }
    cout<<ans;
    return 0;
}
