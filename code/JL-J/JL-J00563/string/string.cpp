#include <bits/stdc++.h>
using namespace std;
long long  a[200005],b[200005];
char c[200005],d[200005],e[200005];
void pe(int n){
    for(int i = 1;i<=n;i++){
        cout<<e[i];
    }
    cout<<endl;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i = 1;i<=n;i++) cin>>a[i]>>c[i];
    int yx = n;//you xiao zi fu
    for(int i = 1;i<=n;i++){
        b[i] = a[i] ;
        d[i] = c[i] ;
    }
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(d[i] == d[j]&&b[j]!='0'){

                b[i]+=b[j];
                b[j] = -1;
                d[j] = '0';
                yx--;
            }
        }
    }
    if(yx == 1) {cout<<0;return 0;}
    int start = 1,ed = n+1;
    int js = 0;char t;int tn = 0;
    for(int i = 1;i<=n;i++){
        if(b[i]!=-1){
            if(b[i]%2 == 0){
                for(int j = 0;j<b[i]/2;j++){
                    e[start] = d[i];
                    start++;ed--;
                }
            }else {js++;t = d[i];tn = b[i];}
        }
    }
    int ans = 0;
    if(js>1) cout<<0;
    else if(js == 1){
        for(int i = 0;i<tn;i++){
            e[start+i] = t;

        }
        start+=tn;

    }
    ans = 0;
    for(int i = 1;i<=start;i++){
        e[start+i-1] = e[i];
    }
    int sd = 1;
    for(int i = 1;;i++){
        if(!c[i])break;
        //cout<<"   "<<a[i]<<endl;
        for(int j = 1;j<=a[i];j++){
            d[sd] = c[i];
            sd++;
            //cout<<d[sd];
        }
    }
    //cout<<endl;
    for(int i = 1;i<=start+start;i++){

        if(c[i]!=e[i]) ans++;

    }
    cout<<ans;


    return 0;
}
