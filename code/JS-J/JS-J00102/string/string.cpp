#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int l,r;char c;
};
vector<node> pp;
string s;
int n,a,ans;
char ch;

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>ch;
        for(int i=0;i<a;i++){
            s+=ch;
        }
    }

    int len=s.size();
    for(int i=0;i<=len/2;i++){
        if(s[i]!=s[len-i-1] && i<len-i-1){
            ans++;
        }
    }
    cout<<ans;
    /*int la=0;
    for(int i=0;i<n;i++){
        cin>>a>>ch;
        pp.push_back({la,la+a-1,ch});
        la=la+a;
    }
    int f=0;

    int g=0,po=n-1,pos=pp[po].r-pp[po].l+1;
    while(g<n){
        if(f==0)break;
        int xl=pp[g].l,xr=pp[g].r;
        if(xr>=la/2-la%2){xr=la/2-la%2;f=1;}
        int xc=xr-xl+1;
        int yl=la-xr-1,yr=la-xl-1;
        if(pos>xc){
            if(pp[g].c!=pp[po].c){
                ans+=xc;
            }
            pos=pos-xc;
        }
         else if(pos==xc){
            if(pp[g].c!=pp[po].c){
                ans+=xc;
            }

            po--;
            pos=pp[po].r-pp[po].l;
        }
        else{
            if(pp[g].c!=pp[po].c){
                ans+=pos;
            }
            po--;
            if(pp[g].c!=pp[po].c){
                ans+=xc-pos;
            }
            pos=pp[po].r-pp[po].l+1-xc+pos;
        }
        g++;
    }
    cout<<ans;


    /*for(int i=0;i<n;i++){
        cout<<pp[i].l<<' '<<pp[i].r<<' '<<pp[i].c<<endl;
    }*/
    return 0;
}
