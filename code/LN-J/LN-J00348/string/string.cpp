#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
struct st{
    long long num;
    char le;
}a[200100];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].le;
    int j=n;
    for(int i=1;i<j;){
        if(a[j].num>a[i].num){
            a[j].num-=a[i].num;
            if(a[i].le!=a[j].le) ans+=a[i].num;
            i++;
        }
        else{
            if(a[j].num<a[i].num){
                a[i].num-=a[j].num;
                if(a[j].le!=a[i].le) ans+=a[j].num;
                j--;
            }
            if(a[i].num==a[j].num){
                if(a[i].le!=a[j].le) ans+=a[i].num;
                i++,j--;
            }
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
