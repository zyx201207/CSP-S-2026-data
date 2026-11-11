#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, m;
    cin >> n >> m;
    int a[200001];
    int max_=-1, max_p, max_2n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(a[i]>max_){
            max_=a[i];
            max_p=i;
        }

    }
    if(m==1){
        cout << max_;
        return 0;
    }

    else if(m == 2){
        int max_and = -1;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                max_and = max(max_and, a[i]&a[j]);
            }
        }
        cout << max_and;
        return 0;
    }
    else if(m == 3){
        int max_and = -1;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                for(int k=j+1; k<=n; k++) max_and = max(max_and, a[i]&a[j]&a[k]);
            }
        }
        cout << max_and;
        return 0;
    }

    else{
        cout << max_;
    }
    return 0;
}
