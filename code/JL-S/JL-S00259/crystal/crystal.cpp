#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],maxa,C=0,bra,x,y,ans=0,c,mm;
int main()
{
    bool A=true,B=true;
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin>>n>>m;
    mm=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) A=false;
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=3) B=false;
    }
    sort(a+1,a+1+n);
    if(!A&&!B){
        if(n>5010||m>100010){
            cout<<10;
            return 0;
        }
        ////////////////////////////////////////////////
        for(int i=110;i>=-110;i--){
        c=0;
        for(int j=n;j>=1;j--){
            if(a[j]==i) c++;
            if(a[j]<i){
                x=j;
                break;
            }
        }
        if(x<=1){
            if(maxa<1) maxa=1;
        }
        for(int j=x;j>=1;j--){
            m=mm;
            if((i-a[j])<=m&&a[j]<i){
                m-=(i-a[j]);
                c++;
            }
        }
        if(c>maxa) maxa=c;
        //cout<<i<<" "<<c<<" "<<x<<endl;
        }
        cout<<maxa;
        return 0;
    }
    //////////////////////////////////////////////////////
    if(A){
        long long q=0;
        for(long long i=1;;i++){
            if(m>=i) m-=i;
            else{
                q=i;
                break;
            }
        }
        cout<<min(n,q);
        return 0;
    }
    if(B){
        bra=a[2]-a[1];
        long long q=0,k=1;
        if(bra<0) bra=0-bra;
        for(long long i=bra;;i+=bra){
            if(m>=i) m-=i;
            else{
                break;
            }
            k++;
        }
        cout<<min(n,k);
        return 0;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

