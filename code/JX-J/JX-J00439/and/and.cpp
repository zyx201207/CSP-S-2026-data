#include <bits/stdc++.h>
using namespace std;
struct b{
    long long z;
    bool y;
}s[2005];
int n,m;
long long f(int c,int w){
    if(m==c){return s[w].z;}
    s[w].y=1;int ax=0;
    for(int i=0;i<n;i++){
        if(s[i].y==0){
            long long a=(s[w].z)&(f(c+1,i));
            if(a>ax){ax=a;}
        }
    }
    s[w].y=0;return ax;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i].z;s[i].y=1;
    }
    int ax=0;
    if(m==1){
        for(int i=0;i<n;i++){if(ax<s[i].z){ax=s[i].z;}}
        cout<<ax;return 0;
    }
    for(int i=0;i<n;i++){
        long long a=f(1,i);
        if(ax<a){ax=a;}
    }
    cout<<ax;
    return 0;
}

