#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],L,c,d,ans,ls;
char b[200005],ls2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n,d=n;
    for(long long i=1;i<=n;i++){
        cin>>ls;
        cin>>ls2;
        a[i]=ls;
        b[i]=ls2;
        L+=a[i];
    }
    L/=2;
    //cout<<L;
    for(int i=1;i<=n;i++){
        if(c+a[i]<=L){
            long long jl=a[i];
            while(jl){
                if(jl>a[d]){
                    if(b[i]!=b[d])ans+=a[d];
                    jl-=a[d],a[d]=0,d--;
                }
                else{
                    if(b[i]!=b[d])ans+=jl;
                    a[d]-=jl,jl=0;
                }
            }
            c+=a[i];
        }
        else{
            a[i]=L-c;
            long long jl=a[i];
            while(jl){
                if(jl>a[d]){
                    if(b[i]!=b[d])ans+=a[d];
                    jl-=a[d],a[d]=0,d--;
                }
                else{
                    if(b[i]!=b[d])ans+=jl;
                    a[d]-=jl,jl=0;
                }
            }
            i=n+1;
            break;
        }
    }
    cout<<ans;
    return 0;
}

