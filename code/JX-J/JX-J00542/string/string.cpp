#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
char str[1000000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    int l=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=l+1;j<=a[i]+l;j++){
            str[j]=c[i];
        }
        l+=a[i];
    }
    bool flag=1;
    int cnt=0;
    for(int i=1;i+i<=l;i++){
        if(str[i]!=str[l-i+1])cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}

