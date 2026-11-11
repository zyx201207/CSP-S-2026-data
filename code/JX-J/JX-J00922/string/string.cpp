#include<bits/stdc++.h>
using namespace std;
char a[200005];
long long b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,k=0;
    cin>>n;
    long long m=0;
    for(int i=1;i<=n;i++){
        long long x;
        char y;
        cin>>x>>y;
        m+=x;
        if(y==a[k]){
            b[k]+=x;
        }else{
            k++;
            a[k]=y;
            b[k]=x;
        }
    }
    bool o=m%2;
    m/=2;
    long long q=0;
    for(int i=1;i<=n;i++){
        q+=b[i];
        if(q>m){
            q-=m;
            q-=o;
            long long r;
            r=b[i]-q-o;
            if(q>r){
                cout<<m-r;
                return 0;
            }else{
                cout<<m-q;
                return 0;
            }
            return 0;
        }else if(q==m){
            cout<<m;
            return 0;
        }
    }
       return 0;
}
