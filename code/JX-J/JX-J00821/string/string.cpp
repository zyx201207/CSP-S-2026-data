#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],sum=0,r,l;
char b[10005];
void f(int x){
    if(a[r]>a[l]){
        a[r]-=a[l];
        l-=1;
        sum+=a[l]*x;
        l+=1;
    }else{
        a[l]-=a[l];
        a[r]=0;
        sum+=a[r]*x;
    }
}

int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);

    cin>>n;
    for(long long i=0;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    r=1;
    l=n;
    while(r<l){
        while(a[r]>0){
                if(b[r]==b[l]){
                    f(0);
                }else{
                    f(1);
                }
                r+=1;


            }
        }

    cout<<sum<<endl;
    return 0;
}
