#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],c;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=29;i>=0;i++){
        c=0;
        for(int j=1;j<=n;j++){
            if(a[j]>=(int)pow(2,i)){
                c++;
                b[c]=a[j];
            }
        }
        if(c>=m) break;
    }
    sort(b+1,b+c+1);
    int sum=b[c];
    for(int i=c-1;i>=c-m;i--){
        sum=sum&b[i];
    }
    cout<<sum;
    return 0;
}
