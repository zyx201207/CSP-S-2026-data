#include<bits/stdc++.h>
using namespace std;
int a[500005], n, m;
int ton[500005];
bool f2;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < a[i - 1]){
            f2 = 1;
        }
    }
    if(!f2){
        for(int i = 1; i <= n; i++){
            vector<int>vec;
            for(int j = i; j <= n; j++){
                vec.push_back(a[j]);
            }
            for(int j = i; j <= n; j++){
                bool f = 0;
                if(*lower_bound(vec.begin(), vec.end(), a[j]) != a[j]){
                    vec.push_back(a[j]);
                }else{
                    int t = lower_bound(vec.begin(), vec.end(), a[j]) - vec.begin();
                    int l = vec.size() - t - 1;
                    for(int k = 0; k < l; k++){
                        vec.pop_back();
                    }
                }
            }
            set<int>st;
            for(auto j : vec){
                st.insert(j);
            }
            for(auto j : st){
                ton[j]++;
            }
        }
        for(int i = 1; i <= m; i++){
            cout << ton[i] << ' ';
        }
        return 0;
    }
    for(int i = 1; i <= n; i++){
        vector<int>vec;
        for(int j = i; j <= n; j++){
            vec.push_back(a[j]);
        }
        for(int j = i; j <= n; j++){
            bool f = 0;
            for(int k = 0; k < vec.size(); k++){
                if(vec[k] == a[j]){
                    int l = vec.size() - k - 1;
                    for(int d = 0; d < l; d++){
                        vec.pop_back();
                    }
                    f = 1;
                    break;
                }
            }
            if(!f){
                vec.push_back(a[j]);
            }
        }
        set<int>st;
        for(auto j : vec){
            st.insert(j);
        }
        for(auto j : st){
            ton[j]++;
        }
    }
    for(int i = 1; i <= m; i++){
        cout << ton[i] << ' ';
    }
    return 0;
}
