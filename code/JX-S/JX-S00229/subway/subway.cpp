#include<bits/stdc++.h>
using namespace std;

int w[1000000];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        int k;
        int num=0;
        cin>>k;
        int a[1000000],t[1000000];
        for(int j=0;j<2*k,j++){
            cin>>a[j]>>t[j];
            num+=a[j]+t[j];
        }
        cout<<num<<endl;
    }
    return 0;
}
