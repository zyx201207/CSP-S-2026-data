#include<bits/stdc++.h>
using namespace std;
struct item{
    int num;
    char c;
};
item spaces[300000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out", "w",stdout);
    int n;
    string s;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        long long times;
        char inputs;
        cin >> times >> inputs;
        spaces[i].num = times;
        spaces[i].c = inputs;
    }
    long long ans = 0;
    int l = 0, r = n-1;
    while(l < r){
        if(spaces[l].c != spaces[r].c){
            int control;
            control = min(spaces[l].num,spaces[r].num);
            ans += control;
            spaces[l].num -= control;
            spaces[r].num -= control;
        }else{
            int control;
            control = min(spaces[l].num,spaces[r].num);
            spaces[l].num -= control;
            spaces[r].num -= control;
        }
        if(spaces[l].num == 0){
            l++;
        }
        if(spaces[r].num == 0){
            r--;
        }
    }
    cout << ans;
    return 0;
}
