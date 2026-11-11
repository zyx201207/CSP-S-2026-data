#include <iostream>
using namespace std;
int n,m,ans,a1[200010];
int an(int a,int b){
    int c=0,d=0,s=1,sum=0;
    while(a){
        c+=a%2*s;
        a/=2;
        s*=10;
    }
    s=1;
    while(b){
        d+=b%2*s;
        b/=2;
        s*=10;
    }
    s=1;
    for(int i=0;i<8;i++){
        if(c%10==d%10&&c%10!=0)
            sum+=s;
        s*=2;
        c/=10;
        d/=10;
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a1[i];
    for(int i=0;i<n;i++)
        for(int j=n;j>i;j--)
                if(an(a1[i],a1[j])>=ans)
                    ans=an(a1[i],a1[j]);
    cout<<ans;
    return 0;
}
