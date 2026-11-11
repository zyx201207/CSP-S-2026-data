#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mi,ans,tmpa=1,tmpb;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=i+1)tmpa=0;
    }
    sort(a,a+n);
    if(tmpa)
    {       long long i=1;
            while(1){
                if(m>i){
                m-=1;
                i++;
                }else{
                cout<<i;
                return 0;
                }
            }
    }
    while(1){
        if(a[tmpb]<a[tmpb+1])
        {
                if(tmpb+1<=m)
                {
                    m-=tmpb+1;
                    for(long long i=0;i<=tmpb;i++)a[i]++;
                }else{
                cout<<tmpb+1;
                return 0;
                }
        }else{tmpb++;}
    }
    cout<<tmpb;
    return 0;
}
