#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","d",stdout);
    int n,m,b[500000],a[500000],A=0,MAX,M;
    cin>>n>>m;
    M=m;
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(int st=0;st<n;st++){
        for(int i=0;i<n;i++)
            a[i]=b[i];
        A=0;
        m=M;
        for(int t=st+1;t<=n;t++){
            for(int j=st;j<=t;j++)
                while(a[j]<a[t]&&m>=1){
                    a[j]++;
                    m--;
                }
            if(m<=0)
                break;
        }
        for(int i=0;i<n;i++)
            if(a[i]==a[st])
                A++;
        MAX=max(A,MAX);
    }
    cout<<MAX;
    return 0;
}
