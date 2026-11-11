#include<bits/stdc++.h>
using namespace std;
struct{
    int a;
    string s;
} w[100005];
long long n,m,maxn,bh,maxl,o,kk;
string  dd(string p,string q){
    string g;
    for(int i=0;i<=max(p.size(),q.size())-1;i++){
        if(q[i]==p[i]&&q[i]=='1')g+='1';
        else g+='0';

    }
    return g;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int l;
    for(int i=0;i<n;i++){
            string p;
        cin>>w[i].a;
        if(maxn<w[i].a){
                maxn=w[i].a;
        bh=i;}
        l=w[i].a;
        while(l>0){
            p+=char((l%2)+'0');
            l/=2;
        }reverse(p.begin(),p.end());
        w[i].s=p;
    }if(m==1){

        cout<<maxn;
    }else{
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string lll=dd(w[i].s,w[j].s);
                o=0,kk=1;
                for(int i=lll.size()-1;i>=0;i--){
                    o+=((lll[i]-'0')*kk);
                    kk*=2;
                }
                maxl=max(o,maxl);
            }
        }cout<<maxl;
    }return 0;
}

