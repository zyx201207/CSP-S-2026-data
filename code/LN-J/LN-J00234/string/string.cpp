#include<bits/stdc++.h>
using namespace std;
//long long
int n;
struct node{
    long long a;
    char c;
}x[200005];
long long ans,l;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i].a>>x[i].c;
        for(int j=l;j<l+x[i].a;j++){
            s[j]=x[i].c;
        }
        l+=x[i].a;
    }
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1])ans++;
        //cout<<s[i]<<' '<<s[l-i-1]<<endl;
    }
    cout<<ans;
    /*int ll=0,rl=0,duo=0;
    bool lc=0,rc=0;
    char lz='',rz='';
    for(int i=1;i<=n;i++){
        if(ll<l)ll+=x[i].a;
        if(rl<l)rl+=x[n-i+1].a;

        if(ll>rl){
            duo=ll-rl;
            lc=1;
        }else if(ll<rl){
            duo=rl-ll;
            rc=1;
        }
    }*/
    return 0;
}
