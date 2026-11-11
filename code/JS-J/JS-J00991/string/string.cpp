#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a,n,cnt=0,xv=0;
    string prmtc,c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c[0];
        for(int j=1+xv;j<=a+xv;j++){
            prmtc[j]=c[0];
        }
        xv+=a;
    }
    for(int i=1;i<=xv/2;i++){
        if(prmtc[i]==prmtc[xv-i+1]){
            continue;
        }
        else{
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
