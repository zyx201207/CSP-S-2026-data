#include<bits/stdc++.h>
using namespace std;
long long n,sum=0;
struct m{
    long long a;
    string c;
};
m s[1000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long l=0,r=n-1;
    for(int i=0;i<n;i++){
        cin>>s[i].a>>s[i].c;
    }
    long long kl=s[0].a,kr=s[n-1].a;
    while(l<r){
        if(s[l].c!=s[r].c){
            sum+=min(kl,kr);
        }
        if(kl>kr){
            kl-=kr;
            kr=s[r-1].a;
            r--;
        }else if(kr>kl){
            kr-=kl;
            kl=s[l+1].a;
            l++;
        }else{
            kl=s[l+1].a;
            kr=s[r-1].a;
            l++;
            r--;
        }
    }
    cout<<sum;
    return 0;
}
