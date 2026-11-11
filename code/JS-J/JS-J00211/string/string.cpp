#include<bits/stdc++.h>
using namespace std;
#define int long long
ifstream fin("string.in");
ofstream fout("string.out");
#define cin fin
#define cout fout
int n,N;
int a[200005];
char c[200005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i]>>c[i];
    for(int i=1;i<=n;++i) N+=a[i];
    int s=0;
    int i=0;
    int j=N;
    int li=0;
    int lj=N;
    int ii=0;
    int jj=n+1;
    while(i<j){
        if(i<=N-j) {
            li=i;
            i+=a[++ii];
        }
        else {
            lj=j;
            j-=a[--jj];
        }
        if(i!=j){
            if(i<=N-j){if(c[ii]!=c[jj]) s+=i-N+lj;}
            else{if(c[ii]!=c[jj]) s+=N-j-li;}
        }
        //cout<<i<<" "<<j<<" "<<li<<" "<<lj<<" "<<ii<<" "<<jj<<" "<<s<<"\n";
    }
    cout<<s<<"\n";
    return 0;
}
