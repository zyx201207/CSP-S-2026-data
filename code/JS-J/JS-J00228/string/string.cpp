#include <bits/stdc++.h>
using namespace std;
struct node{
    long long chang;
    char x;
};
long long ans;
node a[20002];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for (int i = 1;i<=n;i++){
        cin>>a[i].chang>>a[i].x;
    }
    int i = 1;
    int j = n;
    while (i<j){
        if (a[i].x == a[j].x){
            long long k = min(a[i].chang,a[j].chang);
            a[i].chang -= k;
            a[j].chang -=k;
        }
        else{
            long long k = min(a[i].chang,a[j].chang);
            a[i].chang -= k;
            a[j].chang -=k;
            ans+=k;
        }
        if (a[i].chang == 0 ) i++;
        if (a[j].chang == 0) j--;
    }
    cout<<ans;

    return 0;
}
