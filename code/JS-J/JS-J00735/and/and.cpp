#include<bits/stdc++.h>
using namespace std;

long long m=0;
void f(long long b,vector<long long> c,long long n,long long a){
    if(b==0){
        m = max(m,n);
        return;
    }
    for(long long i=0;i<a;i++){
        if(c[i]!=-1){
            long long nn = n&c[i];
            long long e = c[i];
            c[i] = -1;
            f(b-1,c,nn,a);
            c[i] = e;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a,b,d;
    cin>>a>>b;
    vector<long long> c;
    for(long long i=0;i<a;i++){
        cin>>d;
        c.push_back(d);
    }
    if(a==b){
        long long ts=c[0];
        for(long long i=1;i<a;i++){
            ts &= c[i];
        }
        cout<<ts;
    }
    else if(b==1 || a>2000){
        long long ts=0;
        for(long long i=0;i<a;i++){
            ts = max(ts,c[i]);
        }
        cout<<ts;
    }
    else{
        for(long long j=0;j<a;j++){
            long long e = c[j];
            c[j] = -1;
            f(b-1,c,e,a);
            c[j] = e;
        }
        cout<<m;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
