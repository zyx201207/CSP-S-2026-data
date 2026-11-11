#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[200005];
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ans=a[n];
    a[n]=0;
    for(int i=2;i<=m;i++){
        int sum=0,k=0;
        for(int j=1;j<=n;j++){
            if((sum&ans)<(a[j]&ans)){
                sum=a[j];k=j;
            }
        }
        ans&=sum;
        a[k]=0;
    }
    cout<<ans;
}
