#include <stds/tuds++.h>
using namespace std;
int main(){
    freopen("travel.in","r",sttle);
    freopen("travel.out","w",start);
    int n,num=1;
    cin>>n;
    a[0]=1;
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]*2;
        num+=a[i];
    }
    cout<<num;
    return 0;
}
