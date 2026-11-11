#include<bits/stdc++.h>
using namespace std;
struct node{
    char c;
    long long g;
}a[200005],b[200005];
int n;
long long h;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i].g>>a[i].c;
    }
    int l=1,r=n;
    while(l<=r){

        if(a[l].g==0){
            l++;
            continue;
        }
        if(a[r].g==0){
            r--;
            continue;
        }

        if(a[l].c!=a[r].c){
            if(a[l].g<a[r].g){
                ans+=a[l].g;
                a[r].g-=a[l].g;
                l++;
            }else{
                ans+=a[r].g;
                a[l].g-=a[r].g;
                r--;
            }
        }else{
            if(a[l].g<a[r].g){
                a[r].g-=a[l].g;
                l++;
            }else{
                a[l].g-=a[r].g;
                r--;

            }
        }

    }
    cout<<ans;
    return 0;
}
/*






*/
