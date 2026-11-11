#include<bits/stdc++.h>
using namespace std;
struct zfc{
    int a;
    char x;
}z[200005];
long long sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>z[i].a>>z[i].x;
    }
    int l=1,r=n;
    while(l<r){
        if(z[l].a>z[r].a){
            if(z[l].x!=z[r].x){
                sum+=z[r].a;
            }
            z[l].a-=z[r].a;
            r--;
        }
        else if(z[l].a==z[r].a){
            if(z[l].x!=z[r].x){
                sum+=z[l].a;
            }
            l++;
            r--;
        }
        else{
            if(z[l].x!=z[r].x){
                sum+=z[l].a;
            }
            z[r].a-=z[l].a;
            l++;
        }
    }
    cout<<sum;
    return 0;
}
