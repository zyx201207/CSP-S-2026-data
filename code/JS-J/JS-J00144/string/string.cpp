#include <bits/stdc++.h>
using namespace std;
const int MAXN= 2e5+5;//here
//const int MOD= ;

//int T;
int n;
int a[MAXN];
char c[MAXN];
string s=" ";
int pos[MAXN];//2 2 2  2 4 6
int L=0;
int ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        /*for(int j=1;j<=a[i];j++){
            s=s+c[i];
        }*/
        string s2(a[i],c[i]);
        s+=s2;
        L+=a[i];//use string will MLE ba
        pos[i]=pos[i-1]+a[i];//qz shuzu jilu weizhi
    }
    ///cout<<s;
    int l=1;
    while(l<=(L+1)/2){
        if(s[l]!=s[L+1-l]){
            ans++;
        }
        l++;
    }
    cout<<ans;
    return 0;
}
