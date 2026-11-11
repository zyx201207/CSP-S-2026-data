#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long int n;
    cin>>n;
    char  a[200001];
    long long  h=1;
    while(n--){
        long long  cnt;
        char hhh;
        cin>>cnt>>hhh;
        for(long long int i=h;i<=h+cnt-1;i++){
            a[i]=hhh;
        }
        h+=cnt;
    }
    for(long long int i=1;i<=n;i++){
        if(a[i]==a[i-1]){
                continue;
        }
        else {cout<<(h-1)/2;
        return 0;}
    }
    bool ok2=0;
    for(long long int i=0;i<=(h+1)/2;i++){
        if(a[i]==a[h-i]){continue;}
        else if(i==(h+1)/2){continue;}
        else  {cout<<(h-1)/2;return 0;}
    }

    cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}



