#include<bits/stdc++.h>
using namespace std;
long long n,m;
const long long N=3e5+10;
long long a[N],op[N];
long long ans[N];
long long v[N];
void check(long long r){
    for(long long i=1;i<=r;i++){
       ans[a[i]]++;
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    long long tsb=1;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        op[i]=a[i];
        if(a[i-1]>a[i]) tsb=0;
    }
    if(tsb){
        for(long long i=1;i<=n;i++){
           if(a[i]!=a[i+1])
                ans[a[i]]+=i;
        }
        for(long long i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    long long top=0;
    for(long long i=1;i<=n;i++){
        top=0;//cout<<i<<":\n";
        for(long long j=i;j<=n;j++){
            top++;
            //cout<<op[j]<<" ";
            //a[top]=op[j];
            auto it=find(a+1,a+top,op[j]);
            if(*it==op[j])
                top=it-a;
            a[top]=op[j];
            //cout<<top<<endl;

            //cout<<"-1\n";
        }
       // for(long long j=1;j<=top;j++){
               //cout<<a[j]<<" ";
       //  }
        //cout<<endl;
        check(top);
    }
    for(long long i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
