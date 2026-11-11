#include<bits/stdc++.h>
using namespace std;

long long jiaohuan(long long a,long long b){
    long long c;
    if(a>b){
        c=a;a=b;b=c;
    }
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    long long n,m,x=-1,y=1,z=0,xxx;
    cin>>n,m;
    long long a[n];
    for(long long i=0;i<n;i++){
            cin>>a[i];
    }
    //for(int g=0;g<n;g++){
        for(long long i=0;i<n;i++){
            jiaohuan(a[i],a[i+1]);
        }

    /*
    while(s>0){
        for(long long i=0;i<n-1;i++){
            if(a[i]>a[i+1]) jiaohuan(a[i],a[i+1]);
        }
        s--;
    }

    */
    if(n%2!=0) xxx=n/2+1;
    else if(n%2==0) xxx=n/2;

    for(long long i=0;i<n-1;i++){
        if(m>0){// && m-(a[xxx+y]-a[xxx])>0 && m-(a[xxx]-a[xxx+x])>0 && m-(a[xxx]-a[xxx+x])*-1>0 && m-(a[xxx+y]-a[xxx])*-1>0
            if(a[xxx]-a[xxx+x]==a[xxx+y]-a[xxx] && a[xxx+y]-a[xxx]==a[xxx]){
                z+=2;
            }
            else if(a[xxx]-a[xxx+x]>=a[xxx+y]-a[xxx] && a[xxx]-a[xxx+x]>=0 && a[xxx+y]-a[xxx]>=0){
                m-=a[xxx+y]-a[xxx];
                z++;
            }
            else if(a[xxx]-a[xxx+x]<a[xxx+y]-a[xxx] && a[xxx]-a[xxx+x]>=0 && a[xxx+y]-a[xxx]>=0){
                m-=a[xxx]-a[xxx+x];
                z++;
            }
            else if((a[xxx]-a[xxx+x])*-1>=a[xxx+y]-a[xxx] && a[xxx]-a[xxx+x]<0 && a[xxx+y]-a[xxx]>=0){
                m-=a[xxx+y]-a[xxx];
                z++;
            }
            else if((a[xxx]-a[xxx+x])*-1<a[xxx+y]-a[xxx] && a[xxx]-a[xxx+x]<0 && a[xxx+y]-a[xxx]>=0){
                m-=(a[xxx]-a[xxx+x])*-1;
                z++;
            }
            else if(a[xxx]-a[xxx+x]>=(a[xxx+y]-a[xxx])*-1 && a[xxx]-a[xxx+x]>=0 && a[xxx+y]-a[xxx]<0){
                m-=(a[xxx+y]-a[xxx])*-1;
                z++;
            }
            else if(a[xxx]-a[xxx+x]<(a[xxx+y]-a[xxx])*-1 && a[xxx]-a[xxx+x]>=0 && a[xxx+y]-a[xxx]<0){
                m-=a[xxx]-a[xxx+x];
                z++;
            }
            else if((a[xxx]-a[xxx+x])*-1>=(a[xxx+y]-a[xxx])*-1 && a[xxx]-a[xxx+x]<0 && a[xxx+y]-a[xxx]<0){
                m-=(a[xxx+y]-a[xxx])*-1;
                z++;
            }
            else if((a[xxx]-a[xxx+x])*-1<(a[xxx+y]-a[xxx])*-1 && a[xxx]-a[xxx+x]<0 && a[xxx+y]-a[xxx]<0){
                m-=(a[xxx]-a[xxx+x])*-1;
                z++;
            }
        }
        else break;

        x--;y++;

    }
    cout<<z;
}
