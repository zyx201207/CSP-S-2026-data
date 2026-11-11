#include<bits/stdc++.h>
#define endl '\n'
#define pii pair<int,int>
using ll = long long;
using namespace std;
constexpr int N =2*114514;
struct node{
 char c;
 ll b;
} str[N];
ll n,l,r,sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> str[i].b >> str[i].c;
    }
    for(l = 1,r = n ;l < r ; ){
        if(str[l].c == str[r].c){
            if(str[l].b==str[r].b){
                ++l;--r;
                continue;
            }
            if(str[l].b > str[r].b){
                str[l].b-=str[r].b;
                --r;
                continue;
            }
            if(str[l].b < str[r].b){
                str[r].b -= str[l].b;
                ++l;
                continue;
            }
        }
        else{
            if(str[l].b==str[r].b){
                sum+=str[l].b;
                ++l;--r;
                continue;
            }
            if(str[l].b > str[r].b){
                str[l].b-=str[r].b;
                sum+=str[r].b;
                --r;
                continue;
            }
            if(str[l].b < str[r].b){
                str[r].b -= str[l].b;
                sum+=str[l].b;
                ++l;
                continue;
            }
        }
    }
    cout << sum << endl;
    return 0;
}

