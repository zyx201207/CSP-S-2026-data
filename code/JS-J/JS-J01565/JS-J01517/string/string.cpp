#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long num;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n;
    while(i!=j){
        if(c[i]!=c[j]) num+=min(a[i],a[j]);
            if(a[i]>a[j]) {
                a[i]-=a[j];
                j--;
            }
            else if(a[i]<a[j]){
                a[j]-=a[i];
                i++;
            }
            else if(j-i!=1){
                i++;
                j--;
            }
            else break;

    }
    cout<<num;
    return 0;
}
