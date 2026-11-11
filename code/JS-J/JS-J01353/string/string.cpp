#include<bits/stdc++.h>
using namespace std;
long long n;
struct s{
    long long l;
    string c;
}a[200010];
string str1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int si=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].c;
        for(int j=1;j<=a[i].l;j++){
            str1=str1+a[i].c;
        }
        si+=a[i].l;
    }
    long long cnt=0;
    for(int i=0;i<=si-1;i++){
        if(str1[i]!=str1[si-1-i]) cnt++;
    }
    cout<<cnt/2;
    return 0;
}
