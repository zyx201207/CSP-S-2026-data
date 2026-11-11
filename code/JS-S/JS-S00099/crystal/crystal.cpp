#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt=0,num=0,ans=1,l=0,r=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
        cnt+=a[i];
    }
    sort(a,a+n);
    for(int i=a[1];num<=m;i++){
        num+=r;
        if(a[l]<=i){
            r++;
            l++;
        }
    }
    cout << r;
}
