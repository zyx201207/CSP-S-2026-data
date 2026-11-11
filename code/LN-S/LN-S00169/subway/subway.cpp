#include<bits/stdc++.h>
using namespace std;
int ti[1000];
int ans[1000][1000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 0;i<m;i++){
        cin >> ti[i];
    }
    for(int i = 1;i<=n;i++){
        int p;
        cin >> p;
        for(int j = 0;j<p;j++){
            int aa,bb;
            cin >> aa >> bb;
            ans[i][aa] = bb;
        }
    }
    vector<int> arr;
    for(int i = 0;i<q;i++){
        int be,sti;
        cin >> be >> sti;
        queue<int> qu;
        qu.push(be);
        arr.push_back(be);
        while(!qu.empty()){
            if(qu.front() == sti){
                break;
            }
            for(int j = 0;j<1000;j++){
                if(ans[])
            }
        }
    }
}

