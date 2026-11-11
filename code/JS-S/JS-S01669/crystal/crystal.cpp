#include<bits/stdc++.h>
using namespace std;
long long a[500010];long long n,m,c,ma=0;
long long solve(int x){
    long long m1=m,l=1,r=1,k=1;
    for(int i=x-1;i>=1;i--){
        if(m1-(a[x]-a[i])>=0){
            k++;
            m1-=a[i];
        }
    }
    return k;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool f=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=2){
            if(i==2){
                c=a[i]-a[1];
            }
            else if(a[i]-a[i-1]!=c)f=1;
        }
    }
    if(f==0){
        long long h=1,m1=0;
        if(m==0){
            cout<<1<<endl;
            return 0;
        }
        //if(c==1){
           while(m1+m1+c<=m&&h<=n){
                m1+=m1+c;
                h+=1;
            }
            //cout<<m1<<endl;
            cout<<min(h,n)<<endl;
            return 0;
        //}
    }
    else {
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)if(ma<solve(i))ma=solve(i);
        cout<<ma<<endl;
    }
    return 0;
}
