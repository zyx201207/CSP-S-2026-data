#include<bits/stdc++.h>
using namespace std;
int n;
struct ll{
    long long m;
    char c;
}ls[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long x;
        char a;
        cin>>x>>a;
        ls[i].m=x;
        ls[i].c=a;
    }
    long long ans=0;
    int l=1,r=n;
    while(l<=r){
        if(ls[l].c==ls[r].c){
            if(ls[l].m<ls[r].m){
                ls[r].m-=ls[l].m;
                l++;
            }else if(ls[l].m>ls[r].m){
                ls[l].m-=ls[r].m;
                r--;
            }else{
                l++;
                r--;
            }
        }else{
            if(ls[l].m<ls[r].m){
                ls[r].m-=ls[l].m;
                ans+=ls[l].m;
                l++;
            }else if(ls[l].m>ls[r].m){
                ls[l].m-=ls[r].m;
                ans+=ls[r].m;
                r--;
            }else{
                ans+=ls[r].m;
                l++;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
