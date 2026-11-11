#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,asum=0,a,cnt=0;
    char c[100000],l;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>l;
        for(int j=asum+1;j<=(asum+a);j++){
            c[j]=l;
        }
        asum+=a;
    }
    long long aa=asum/2+1;
    for(int i=1;i<=aa;i++){
        if(c[i]!=c[asum-i+1]){
            cnt+=1;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
