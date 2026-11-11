#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    long long a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int max_ = -1;
    for(int i = 0;i < m;i++){
        if(max_ == -1){
            max_ = a[i];
        }
        max_ = max_ & a[i];
    }
    for(int i = 0;i < (1 << n);i++){
        int yu = -1;
        int num = 0;
        for(int j = 0;j < n;j++){
            if(i & (1 << j)){
                num++;
                if(yu == -1){
                    yu = a[j];
                }
                yu &= a[j];
            }
        }
        if(num != m){
            continue;
        }
        if(yu > max_){
            max_ = yu;
        }
    }
    cout << max_;
    fclose(stdin);
    fclose(stdout);
    return 0;
}



