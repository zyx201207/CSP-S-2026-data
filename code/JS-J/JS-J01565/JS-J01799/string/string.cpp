#include <bits/stdc++.h>
using namespace std;
struct zc{
    int a;
    char c;
};
zc zoc[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>zoc[i].a>>zoc[i].c;
    }
    int l=0,r=n-1,k;
    long long cs=0;
    while(l<r){
        k=1;
        if(zoc[l].c==zoc[r].c){
            k=0;
        }
        if(zoc[l].a>zoc[r].a){
            if(k)
                cs+=zoc[r].a;
            zoc[l].a-=zoc[r].a;
            r--;
        }
        else {if(zoc[l].a==zoc[r].a){
                if(k)
                    cs+=zoc[r].a;
                l++;
                r--;
            }
            else{
                if(k)
                    cs+=zoc[l].a;
                zoc[r].a-=zoc[l].a;
                l++;
            }
        }
    }
    cout<<cs<<endl;
    return 0;
}
