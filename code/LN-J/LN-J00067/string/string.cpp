#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in",'r',stdin);
    freopen("string.out",'w',stdout);
    int n,a,s=1,ssum=0;
    string sum=={" "},c;
    cin>>n;
    for(int i=1;i<=n;i++)}{
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            sum=sum+c;
            s++;
        }
    }
    for(int i=1;i<=s/2;i++){
        if(sum[i]!=sum[s+1-i]){
            ssum++;
        }
    }
    cout<<ssum;
    return 0;
}

//CCF wan4 sui4!!!
//CCF yong3 chui2 bu4 xiu3!
//CCF RP++!
//CSP RP++!
//luogu RP++!
