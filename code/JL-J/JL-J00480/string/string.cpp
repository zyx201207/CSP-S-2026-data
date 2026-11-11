# include <bits./stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[10000000000000],num=0;
    cin>>n
    char c[1000000000000],b[1000000000000000];
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        num=num+a[i];
    }
    num=num/2;
    cout<<num;
    return 0;
}
