#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
const int maxn = 2e5+10;
int n;
ll a[maxn],c[maxn],ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    char x;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>x;
        c[i] = x-'a';
    }
    /*for (int i=1;i<=n;i++){
        for (int j=1;j<=a[i];j++){
            cout<<char(c[i]+'a');
        }
        cout<<" ";
    }
    cout<<"\n";*/

    int i=1,j=n;
    while (i<j){
        if (a[i] == a[j]){
            if (c[i] != c[j]){
                ans += a[i];
            }
            i++;
            j--;
        }
        else if (a[i]<a[j]){
            if (c[i]!= c[j]){
                ans += a[i];
            }
            a[j] -= a[i];
            i++;
        }
        else if (a[i]>a[j]){
            if (c[i]!=c[j]){
                ans += a[j];
            }
            a[i] -= a[j];
            j--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
