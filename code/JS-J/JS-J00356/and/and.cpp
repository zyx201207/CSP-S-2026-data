#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //
    int n;
    int m;
    cin>>n>>m;
    int a;
    int s1,s2;
    for(int i=0;i<=n;i++){
        int b;
        int c;
        cin>>a;
        b=b+a%2;
        a=a/10;
        c=c+m%2;
        m=m/10;
        s1=c&b;
        s2=b&c;
    }
    for(int i=0;i<=n;i++){
        if(s1>s2){
            s2=s1;
        }
        else if(s1<=s2){
            s2=s2;
        }
    }
    cout<<s2;
    return 0;
}
