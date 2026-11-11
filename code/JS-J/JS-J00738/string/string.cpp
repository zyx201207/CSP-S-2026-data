#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
    long long a;
    char c;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].c;
    }
    int i=1,j=n;
    while(i<j){
        if(a[i].c==a[j].c){
            if(a[i].a>a[j].a){
                a[i].a-=a[j].a;
                j--;
            }
            else if(a[i].a==a[j].a) a[i].a=a[j].a=0,i++,j--;
            else{
                a[j].a-=a[i].a;
                i++;
            }
        }
        else{
            if(a[i].a>a[j].a){
                a[i].a-=a[j].a;
                ans+=a[j].a;
                j--;
            }
            else if(a[i].a==a[j].a){
                ans+=a[i].a;
                i++,j--;
            }
            else{
                a[j].a-=a[i].a;
                ans+=a[i].a;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
