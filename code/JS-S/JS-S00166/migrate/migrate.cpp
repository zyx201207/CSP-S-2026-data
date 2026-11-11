#include<bits/stdc++.h>
using namespace std;
long long T,c,x[2000005],p,n,d,k,y,z,i,j;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        k=0;
        cin>>n>>d;
        for(i=0;i<n;i++)
            cin>>x[i];
        for(i=0;i<n;i++){
            j=p=i;
            j++;
            while(j<n&&x[j]-x[p]<=d)
                j++;
            y=j-i-1;
            while(j<n){
                while(j<n&&x[j]-x[p]<=d){
                    if(j-p==y)
                        k++;
                    j++;
                }
                p=j-1;
            }
        }
        cout<<k<<endl;
    }
    return 0;
}
