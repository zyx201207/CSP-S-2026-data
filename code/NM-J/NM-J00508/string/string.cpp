#include <bits/stdc++.h>
using namespace std;
#define N 200008
#define ull unsigned long long
ull a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 0;i < n;++i){
        cin>>a[i]>>c[i];
    }
    ull result = 0;
    ull la = 0,ra = 0;
    char lc,rc;
    int li = 0,ri = n - 1;
    while(true){
    //    cout<<la<<lc<<ra<<rc<<endl;
        if(la == 0){
            lc = c[li];
            la = a[li];
            ++li;
        }
        else if(ra == 0){
            rc = c[ri];
            ra = a[ri];
            --ri;
        }
        else{
            ull k = (la > ra ? ra : la);
            if(lc != rc)
                result += k;
            la -= k;
            ra -= k;
            if(li > ri) break;
        }
    }
    cout<<result;
    return 0;
}
