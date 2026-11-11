#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[500009];
int b[500009];
long long rev=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long jz=0;
    long long z=0;
    long long sum=0;
    long long total=0;
    long long total2=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        z+=a[i];

    }
    a[0]=0;
    int cha=a[2]-a[1];
    sort(a+1,a+n+1);
    long long mid=(z+m)/n;
    int nt=a[1];
    //for(int i=1;i<=n;i++){
        for(int i=1;i<=n;i++){
        if(abs(a[i]-mid)<=abs(nt-mid))
        {
            nt=a[i];
            jz=i;

     }
    }
    //}
    //cout<<jz;
     for(int i=1;i<jz;i++){
        b[i]=abs(nt-a[i]);
        //cout<<b[i];
     }
     sort(b,b+jz);
     for(int i=1;i<jz;i++){
        //rev+=b[i];
        //cout<<b[i]<<' ';
        if(m-b[i]>=0){
            m-=b[i];
            a[i]=nt;
           //rev=0;
            //cout<<m;
        }
        else{
            break;
        }
    }


    for(int i=1;i<=n;i++){
        if(a[i]==nt) total++;
    }

cout<<total;
}
