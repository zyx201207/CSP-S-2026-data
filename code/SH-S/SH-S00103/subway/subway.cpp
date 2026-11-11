#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long t[501];
int b1[200],b2[200],c1[200],c2[200];
int x[1000000000000],y[100000000000000]
int a[100000000];
void add(int c,int g){
    int cnt = 0;
    if(x[c]<j[c]){
        for(int i=x[c];i<y[c],i++){
            cnt+=b2[i];
            cnt+=t[i]
        }
    }
    else{
        for(int i = y[c];i>x[c];i++){
            cnt+=b2[i];
            cnt+=t[i];
        }
    }
    return cnt;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 0;i<m;i++){
        cin>>t[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<a[i];j++){
            cin>>b1[i]>>b2[j]>>c1[i]>>c2[j];
        }
    }
    for(int i = 0;i<q;i++){
        cin>>x[i]>>y[i];
    }
    int f=0;
    for(int i = 0;i<q;i++){
        int s = 0;
        for(int j = 0;j<n;j++){
            if(x[i]==b2[j]) s=1
            if(j[i]==b2[j]&&s==1) s==2;
            if(s==2) cout<<add(i,f);
        }
        f++;
    }
    return 0;
}
