#include<bits/stdc++.h>
using namespace std;
long long m,n,d[10005],s=0,e[10005],lll;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>m>>n;
    for(int i=0;i<m;i++) cin>>d[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(d[j]>s) s=d[j];
        }
        for(int j=0;j<m;j++){
            if(d[j]==s) d[j]=0;
        }
        e[i]=s;
        s=0;
    }
    lll=e[0];
    for(int i=1;i<n;i++){
        lll=lll&e[i];
    }
    cout<<lll;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
