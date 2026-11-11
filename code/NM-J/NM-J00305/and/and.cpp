#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","in",stdin);
    freopen("and.out","out",stdout);
    vector<int> a;
    long long n;
    long long m;
    int kj;
    int h;
    int gd;
    cin >> n;
    cin >> m;
    for(int i;i <= n;i++){
        cin >> h;
        a.push_back(h);
    }
    int g ;
    g = a.size();
    for(int tr = 0;tr < g;tr++){
        for(int tp = 0;tp < g;tp++){
            if(a[tp] < a[tp+1]){
                kj = a[tp];
                a[tp] = a[tp+1];
                a[tp+1] = kj;
            }
        }
    }
    for(int oy = 0;oy < m;oy++){
        if(oy = 0){
            gd = a[oy] & a[oy+1];
        }
        gd = gd & a[oy+1];
    }
    cout << gd;
    return 0;
}

