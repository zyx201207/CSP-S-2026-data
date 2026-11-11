#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
struct zm{
int num;
char c;
}a[200005];
string s;
long long maxl=0;
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].c;
        maxl+=a[i].num;
    }
    long long l=1,r=maxl,i=1,j=a[n].num,cnt1=1,cnt2=n;
    while(l<=r){
        if(i>a[cnt1].num){
            cnt1++;
            i=1;
        }
        if(j<1){
            cnt2--;
            j=a[cnt2].num;
        }
        if(a[cnt1].c!=a[cnt2].c){
            ans++;
        }
        i++;
        j--;
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}
