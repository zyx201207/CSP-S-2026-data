#include <iostream>

using namespace std;
long long c,t,n,d,a[100000],b[100000],sum=0;
void f(int ad,int cnt){
    for(int i=ad+1;i<=n;i++){
        if(d>=a[ad]-a[i]){
            if(b[i]==cnt+1){
                sum++;
            }else{
                b[i]=cnt+1;
            }
        }
        f(i,cnt+1);
        cout<<endl;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.in","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n>>d;
        sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=0;
        }
        f(1,0);
        cout<<sum<<endl;
    }
    return 0;
}
