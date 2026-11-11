#include<bits/stdc++.h>
using namespace std;
struct Str{
    char q;
    long long num, l, r, sh;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n; string s = ""; cin>>n;
    long long sum = 0, ans = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i].num>>a[i].q;
        a[i].l = sum+1;
        sum += a[i].num;
        a[i].r = sum;
        a[i].sh = a[i].num;
    }
    a[n+1].l = n+1;
    int l1 = 1, r1 = n;
    for(long long i = 1, j = sum;i<=sum/2 && r1>=l1;){
        if(a[l1].sh>=a[r1].sh){
            i += a[r1].sh;
            j -= a[r1].sh;
            a[l1].sh-=a[r1].sh;  
            if(a[l1].q != a[r1].q){
                ans+=a[r1].sh;
            }
            a[r1].sh = 0;
            --r1;
        }else{
            i+=a[l1].sh;
            j-=a[l1].sh;
            a[r1].sh-=a[l1].sh;
            if(a[l1].q != a[r1].q){
                ans+=a[l1].sh;
            }
            a[l1].sh = 0;
            ++l1;
        }
    }
    cout<<ans;
    return 0;
}
