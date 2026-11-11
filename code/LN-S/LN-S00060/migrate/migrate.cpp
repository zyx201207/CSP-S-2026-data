#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    long long c,t,aa,i,j,k,a[2000005];

    cin>>c>>t;

    for(aa=1;aa<=t;aa++){

        long long n,d,sum(0),ans(0);
        ans=0;

        cin>>n>>d;

        for(i=1;i<=n;i++){
            cin>>a[i];
        }

        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){

            if((a[j]-a[i]>d)&&(a[j]-a[i]<=2*d)){
                    sum=0;

                for(k=i+1;k<j;k++){

                    if((a[k]-a[i]<=d)&&(a[j]-a[k]<=d)){
                        sum++;
                    }
                }
                if(sum==2){
                    ans++;
                    sum=0;
                }
           }


        }

        }



cout<<ans<<endl;









    }


    return 0;
}
