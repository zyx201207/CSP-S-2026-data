#include<bits/stdc++.h>
using namespace std;
int n;
char r[100000005],l[100000005],lh[1000000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int t=0,js=1,sum=0;
    char x;
    for(int i=1;i<=n;i++){
        cin>>t>>x;
        for(int j=js;j<=t+js-1;j++){
            lh[j]=x;
            sum++;
        }
        js=sum+1;
    }
    int r1,l1;
    if(sum%2!=0){
        r1=sum/2;
        l1=sum/2+1;
    }
    else{
        r1=sum/2;
        l1=sum/2;
    }
    for(int i=1;i<=r1;i++){
        r[i]=lh[i];
    }
    int y=0;
    for(int i=l1;i<=sum;i++){
        l[y]=lh[i];
        y++;
    }
    int g=0;
    for(int i=1;i<=sum/2;i++){
        if(r[r1-i+1]!=l[i]){
            g++;
        }
    }
    cout<<g;
    return 0;
}
