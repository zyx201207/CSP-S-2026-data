#include<bits/stdc++.h>
using namespace std;
struct xy{
    int a1;
    char c;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a1>>a[i].c;
    }
    int l=1,r=n;
    long long cnt=0;
    while(l<=r){
        if(a[l].a1<=a[r].a1){
            if(a[l].a1==a[r].a1){
                    if(a[l].c!=a[r].c){
                        cnt+=a[l].a1;
                    }
                l++;
                r--;
            }
            else{
                a[r].a1-=a[l].a1;
                if(a[l].c!=a[r].c) cnt+=a[l].a1;
                l++;
            }
        }
        else{
            a[l].a1-=a[r].a1;
            if(a[l].c!=a[r].c) cnt+=a[r].a1;
            r--;
        }
    }
    cout<<cnt;
    return 0;
}
