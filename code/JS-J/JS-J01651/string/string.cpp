#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st{
    ll num=0;
    string a="";
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<st>str1(n);
    ll b=0;
    for(ll i=0;i<n;i++){
        ll n1;
        string a1;
        cin>>n1>>a1;
        if(b==0){
            str1[b].num+=n1;
            str1[b].a=a1;
        }
        else{
            if(a1==str1[b-1].a){
                str1[b-1].num+=n1;
                b--;
            }
            else{
            str1[b].num+=n1;
            str1[b].a=a1;
            }
        }
        b++;
    }
    ll w=0,w0=0;
    ll n2=0;
    for(ll i=0;i<str1.size();i++){
        if(str1[i].num!=0){
            w++;
            n2+=str1[i].num;
        }
        else break;
    }
    ll cum=0;
    while(w-w0>1){
        if(str1[w0].num<=n2/2||str1[w-1-w0].num<=n2/2){
            if(str1[w0].a==str1[w-1-w0].a){
                ll n3=min(str1[0].num,str1[w-1].num);
                str1[w0].num-=n3;
                str1[w-1-w0].num-=n3;
                if(str1[w0].num==0)w0++;
                else w--;
                n2-=(2*n3);
            }
            else{
                ll n3=min(str1[0].num,str1[w-1].num);
                str1[w0].num-=n3;
                str1[w-1-w0].num-=n3;
                if(str1[w0].num==0)w0++;
                else w--;
                n2-=(2*n3);
                cum+=n3;
            }
        }
    }
    cout<<cum;
}
