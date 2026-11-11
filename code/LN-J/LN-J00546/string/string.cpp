#include <bits/stdc++.h>
using namespace std;

long long tbb[1000010][3];int n;

int get_gg(int suoyin){
    for (int i=0;i<n;i++){
        if (suoyin>=tbb[i][0]&&suoyin<=tbb[i][1]){
            return tbb[i][2];
        }
    }return 0;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int suo1=0;int suo2;
    int hl;char cl;long long leng=0;
    for(int i=0;i<n;i++){
        cin >> hl >> cl;
        suo2 = suo1+hl-1;
        tbb[i][0] = suo1;
        tbb[i][1] = suo2;
        tbb[i][2] = cl;
        suo1+=hl;
        leng += hl;
    }
    int valid1,valid2;
    if (leng%2==1){
        valid1 = (leng-1)/2;
        valid2 = valid1 +2;
    } else{
        valid1 = leng/2;
        valid2 = valid1 +1;
    }
    valid1--;
    valid2--;
    long long res=0;
    while (valid1 >=0){
        if (get_gg(valid1)!=get_gg(valid2)){
            res++;
        }valid1--;
        valid2++;
    }cout<<res;

    return 0;
}
