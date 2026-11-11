#include<bits/stdc++.h>
using namespace std;
long long a,b[1005],n,t,p,q;
string c[1005],d[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b[i];
        cin>>c[i];
        n+=b[i];
    }
    for(int i=1;i<=n;i++){
        p=b[i];
        for(int j=0;j<p;j++){
            d[j]=c[q];
        }
        q++;
    }
    if(n%2==1){
        n=n/2+1;
    }else{
        n=n/2;
    }
    for(int i=0;i<n;i++){
        if(d[i]!=d[n-1]&&n%2==0){
            t++;
        }else if(d[i]!=d[n-1+1]){
            t++;
        }
    }
    cout<<t;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
