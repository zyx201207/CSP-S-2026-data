#include<bits/stdc++.h>

using namespace std;

int n,m;
long long bin[200001];

int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    long long m_b = 0;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> bin[i];
        m_b = max(bin[i],m_b);
    }

    //get meaningful bin's number:
    m_b = log2(m_b)+1;

    while(true){
        int c_total = 0;
        for(int i = 0 ; i < n ; i++){
            if((bin[i]>>m_b)&1 == 1){
                c_total++;
            }
        }
        if(c_total >= m){
            break;
        }

        m_b--;
    }

    //get new menu
    vector<int> n_bin;//vector:new bin
    for(int i = 0 ; i < n ; i++){
        if((bin[i]>>m_b)&1 == 1){
            n_bin.push_back(bin[i]);
        }
    }int n_n = n_bin.size();


    //find it
    int and_r;
    while(m_b > 0){
        int con = 0;
        m_b--;
        for(int i = 0 ; i < n_n ; i++){
            if((n_bin[i]>>m_b)&1 == 1){
                con++;
            }
        }if(con >= m){
            vector<int> one;
            for(int i = 0 ; i < n_n ; i++){
                if((n_bin[i]>>m_b)&1 == 1){
                    one.push_back(n_bin[i]);
                }
            }n_bin = one;
            n_n = n_bin.size();
        }
    }
    and_r = n_bin[0];
    for(int i = 1 ; i < m ; i++){
        and_r &= n_bin[i];
    }

    cout << and_r;

    return 0;
}