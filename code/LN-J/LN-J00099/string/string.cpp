#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.in","w",stdout);
    long long n,num=0,pp=0,kl,sum=0,po;
    string a[100005],jj;
    cin>>n;
    if(n==1){
        cout<<0;
    }
    else if(n==2){
        for(int i=0;i<n*2;i++){
            cin>>a[i];
        }
        if(a[1]==a[3]){
            cout<<0;
        }else{
            cout<<min(a[0],a[2]);
        }
    }else{
        for(int i=0;i<n*2;i+=2){
            cin>>pp;
            sum+=pp;
            kl=pp;
            cin>>a[i/2+pp*i/2];
            jj=a[i/2+pp*i/2];

            for(int p=1;p<pp;p++){
                a[i+p]=jj;
            }
            pp=0;
        }

        for(int l=0;l<sum/2;l++){
            if(a[l]!=a[sum-1-l]){
                num++;
            }
        }
        cout<<num;

    }
    return 0;
}
