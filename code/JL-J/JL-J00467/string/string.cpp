#include <bits/stdc++.h>
using namespace std;
int n;
long long cnt=0;
struct ans{
    char alph;
    long long num;
}b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("strinf.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>b[i].num>>b[i].alph;
    int l=1,r=n;
    while(l<r){
        if(b[l].alph==b[r].alph){
            if(b[l].num<b[r].num){
                b[r].num-=b[l].num;
                l++;
            }
            else if(b[l].num>b[r].num){
                b[l].num-=b[r].num;
                r--;
            }
            else{
                l++;
                r--;
            }
        }else{
            if(b[l].num<b[r].num){
                cnt+=b[l].num;
                b[r].num-=b[l].num;
                l++;
            }
            else if(b[l].num>b[r].num){
                cnt+=b[r].num;
                b[l].num-=b[r].num;
                r--;
            }
            else{
                cnt+=b[l].num;
                l++;
                r--;
            }
        }
    }
    cout<<cnt;
    return 0;
}
