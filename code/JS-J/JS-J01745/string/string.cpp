#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,num=0;
    cin>>n;
    int a[200010];
    char c[200010];
    char ans[7378681];
    long long x=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        x=x+a[i];
    }
    int k=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            k++;
            ans[k]=c[i];
        }
    }
    for(int l=1;l*2<=x;l++){
        int r=x-l+1;
        if(ans[l]!=ans[r])num++;
    }
    cout<<num;
    return 0;
}
