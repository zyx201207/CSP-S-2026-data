#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m,a[14524],sum=0,x=0,i,j;
    string s,t;
    char f[14875];
    cin>>n;
    if(n<=1){
        cout<<0<<endl;
        return 0;
    }
    for(i=0;i<n;i++){
        cin>>a[i]>>f[i];
    }
    if(n==2){
        if(f[0]!=f[1])cout<<min(a[0],a[1]);
        else{
            cout<<0<<endl;
        }
        return 0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<a[i];j++){//x size
            s[x]=f[i];
            x++;
        }
    }
    for(i=0;;i++){
        if(x-2*i<0)break;
        char r1=s[x-i];
        char r2=s[i];
        if(r1!=r2){
            sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
