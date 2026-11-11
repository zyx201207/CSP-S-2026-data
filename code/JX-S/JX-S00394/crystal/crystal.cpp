#include<bits/stdc++.h>
using namespace std;
long long a[500001],qian[500001];
long long n,m;
bool check(long long x){
    long long mi=1e18;
    //cout<<"x="<<x<<endl;
    for(int i=1;i<=n-x+1;i++){
        long long goal=a[i+x-1]*x;
        long long now=qian[i+x-1]-qian[i-1];
        if(goal-now<=m){
            //cout<<"goal="<<goal<<" now="<<now<<endl;
           // cout<<"t="<<a[i]<<" w="<<a[i+x-1]<<endl;
            return 1;
        }
    }
    return 0;

}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    //cout<<"m="<<m<<endl;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        qian[i]=qian[i-1]+a[i];
    }
    long long l=1,r=n,an=0,p=1;
    while(1){
        an=(l+r)/2;
        if(check(an)){
            l=an+1;
            p=an;
        }
        else{
            r=an-1;
        }
        if(l>r){
            break;
        }
    }
    cout<<p;
    return 0;
}
