/*#include <bits/stdc++.h>
using namespace std;
struct DATA{
    int x;
    int y;
    char c;
};
struct DATAA{
    int n;
    char c;
};
DATA s[200005];
int n;
bool h(string b){
    string a = b;
    reverse(b.begin(),b.end());
    if(a == b){
        return 1;
    }
    return 0;
}
char d(int xx){
    for(int i = 0;i <n;i++){
        if(xx >= s[i].x && xx <= s[i].y){
            return s[i].c;
        }
    }
    return '-';
}
vector<DATAA> e(int x,int y){
    vector<DATAA> a;
    for(int i = 0;i < n;i++){
        if(s[i].y >= x){
            if(y <= s[i].y){
                a.push_back({y-s[i].x+1,s[i].c});
                break;
            }
            a.push_back({s[i].y - x + 1,s[i].c});
            x++;
        }
    }
    return a;
}
int main(){
   // freopen("string3.in","r",stdin);
   // freopen("string3.out","w",stdout);

    cin >> n;
    int x = 0;
    for(int i = 0;i < n;i++){
        int num;
        char c;
        cin >> num >> c;
        s[i].x = x;
        s[i].y = x + num - 1;
        s[i].c = c;
     //   cout << x + num - 1 << endl;
        x += num;

    }
    int len = s[n - 1].y + 1;
    //cout << len << endl;
    bool u = len % 2;
    int sum = 0;
    if(u){
        vector<DATAA> ae = e(0,len / 2 - 1);
        vector<DATAA> be = e(len / 2 + 1,len - 1);
        reverse(be.begin(),be.end());
        for(int i = 0;i < ae.size();i++){
            if(!(ae[i].c == be[i].c && ae[i].n == be[i].n)){

            }
        }
    }
    else{
        vector<DATAA> ae = e(0,len / 2 - 1);
        vector<DATAA> be = e(len / 2,len - 1);
        reverse(be.begin(),be.end());
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
bool h(string b){
    string a = b;
    reverse(b.begin(),b.end());
    if(a == b){
        return 1;
    }
    return 0;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s = "";
    for(int i = 0;i < n;i++){
        int num;
        char c;
        cin >> num >> c;
        for(int j = 0;j < num;j++){
            s += c;
        }
    }
    int sum = 0;
    int x = 0;
    int y = s.size() - 1;
    while(!h(s)){
        if(s[x] == s[y]){
            x++;y--;
            continue;
        }
        s[x] = s[y];
        x++;
        y--;
        sum++;
    }
    cout << sum << endl;
    return 0;
}
