#include<bits/stdc++.h>
using namespace std;
long long n=0,b[200005],s=0;
char a[200005];
string c="";
void eq(){
    long long p=c.size();
    long long mid=(c.size())/2,sum=0;
    for(int i=0;i<mid;i++){
        if(char(c[i])==char(c[p-i-1])){
            continue;
        }
        sum++;
    }
    cout<<sum;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i]>>a[i];
        for(int j=1;j<=b[i];j++){
            c+=a[i];
        }
    }
    eq();
    return 0;
}
