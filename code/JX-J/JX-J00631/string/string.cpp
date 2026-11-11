#include <bits/stdc++.h>

using namespace std;

struct S{
    int lon, ind=0;
    char ch;
};
const int N=2e5+5;
S lst[N];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    long long ans=0, sum=0;
    int l, r, add;
    long long lsm=0, rsm=0;
    cin>>n;
    l=0; r=n;
    for(int i=1; i<=n; i++){
        cin>>lst[i].lon>>lst[i].ch;
        sum+=lst[i].lon;
    }
    for( ; l+1<r&& lsm+lst[l+1].lon<=sum/2; ){
        l++;
        lsm+=lst[l].lon;
        for( ; l<r&& rsm+(lst[r].lon-lst[r].ind)<=lsm; r--){
            add=(lst[r].lon-lst[r].ind);
            rsm+=add;
            if(lst[r].ch!=lst[l].ch) ans+=add;
        }
        add=lsm-rsm;
        lst[r].ind+=add;
        //cout<<lst[r].ind<<endl;
        rsm=lsm;
        if(lst[r].ch!=lst[l].ch) ans+=add;
        //printf("%d %d %ld %ld\n", l, r, lsm, rsm);
    }
    if(l!=r){
        l++;
        for( ; r>l; r--){
            add=(lst[r].lon-lst[r].ind);
            //rsm+=add;
            if(lst[r].ch!=lst[l].ch) ans+=add;
        }
        //printf("%d %d %ld %ld\n", l, r, lsm, rsm);
    }
    cout<<ans;
    return 0;
}
