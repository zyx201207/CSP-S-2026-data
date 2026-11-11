#include<bits/stdc++.h>
using namespace std;
int c[300005];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    string s,b;
    char a[500005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int m2=1;m2<=n;m2++){
        for(int i=m2;i<=n;i++){
            s+=a[i];
        }
        for(int j=1;j<=n;j++){
            if(s[1]==s[j]){
                b="";
                b+=s[j];
            }else{
                b+=s[j];
            }
        }
        for(int i=1;i<b.size();i++){
            c[b[i]-'0']++;
        }
        s="";
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]+2<<' ';
    }
    return 0;
}

