#include"bits/stdc++.h"
using namespace std;

int a[20005],s[20005][20005];
//bool v[20005];
int maxa=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //int q=2,w=3;
    //cout<<(q & w)<<endl;
    int n,m;cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        s[i][1]=a[i];
//        cout<<s[i][1]<<' ';
//        cout<<s[i][1]<<' ';
    }
//    cout<<endl;
    for(int i = 2;i <= m;i++){ //times

        for(int j=i;j <= n;j++){
            //cout<<s[j][i]<<' ';
            for(int z= 1;z < j;z++){
                s[j][i] = max(s[j][i],(s[z][i-1] & a[j]));
            }
            //cout<<s[j][i]<<' ';
        }
        //cout<<endl;
    }
    for(int i = 1+m;i <= n;i++){
        maxa=max(maxa,s[i][m]);
    }
    cout<<maxa;
}
