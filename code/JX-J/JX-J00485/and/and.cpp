#include<bits/stdc++.h>
using namespace std;
const int N=2e3;
int n,m,a[N],dabiao[30];
bool A=1,B=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m>>a[1];
    if(a[1]!=0)B=0;
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]!=a[i-1])A=0;
        if(a[i]!=i-1)B=0;
    }
    for(int i=1;i<=30;i++){
        dabiao[i]=pow(2,i);
    }
    if(A==1){
        cout<<a[1];
        return 0;
    }else if(B==1){
        int ans=0;
        for(int i=m;i<=2;i--)ans&=a[i];
        cout<<ans;
        return 0;
    }else{
        sort(a+1,a+1+n);
        cout<<a[n]&a[n-1];
    }
    //cout<<dabiao[10];
    //ji de shan diao zhu shi o
    return 0;
}
