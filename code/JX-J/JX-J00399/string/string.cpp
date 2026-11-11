#include<bits/stdc++.h>
using namespace std;
int n;
char a,c[1000000005];
long long cnt,sum,a1;
//string c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a1>>a;
        for(int j=sum+1;j<=sum+a1;j++)c[j]=a;
         sum+=a1;
    }
    //for(int i=1;i<=sum;i++)cout<<c[i];
    for(long long i=1;i<=(sum+1)/2;i++){
        if(c[i]!=c[sum+1-i])cnt++;
    }
    cout<<cnt;
    return 0;
}
