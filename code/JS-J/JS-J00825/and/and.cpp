#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#define int long long
using namespace std;

int n, m;
int ans = 0;
vector <int> a[200005]={};
int t[200005]={};

void fs(int i){
    stack <int> s;
    for(; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(a[j][i]){
                s.push(j);
            }
        }
        if((int)s.size() < m){
            while(!s.empty()){
                s.pop();
            }
        }else{

            for(; i >= 0; i--){
                bool f = false;
                for(int j = n-1; j >=0; j--){
                    if(!a[j][i]){
                         if((int)s.size() > m){
                            s.pop();
                         }else{
                            f=true;
                         }
                    }
                }
                if(f){continue;}
                if(!a[s.top()][i]){
                    ans += (1<<i);
                }
            }


        }
    }




    return;
}

signed main(){
    freopen("and.in","r", stdin);
    freopen("and.out","w", stdout);
    cin >> n >> m;
    int C = 31;
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    sort(t,t+n);
    for(int i = 0; i < n; i++){
        while(C--){
            a[i].push_back(t[i] & (1<<C));
        }
    }
    int in = 31;
    fs(in);
    cout << ans;

    return 0;
}
