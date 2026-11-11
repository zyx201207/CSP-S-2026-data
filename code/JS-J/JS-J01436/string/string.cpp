#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, l, r, cnt;
struct node{
    long long a;
    char c;
}s[N];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for(long long i = 1; i <= n; i++){
        cin >> s[i].a >> s[i].c;
    }
    long long i = 1, j = n;
    while(i < j){
        if(l != 0 && r == 0){
            while(l >= s[j].a){
                if(s[i].c != s[j].c){
                    cnt += s[j].a;
                }
                l -= s[j].a;
                j--;
            }
            if(l == 0){
                i++;
                continue;
            }
            if(l < s[j].a){
                if(s[i].c != s[j].c){
                    cnt += l;
                }
                r = s[j].a - l;
                l = 0;
                i++;
            }
        }else if(l == 0 && r != 0){
            while(r >= s[i].a){
                if(s[i].c != s[j].c){
                    cnt += s[i].a;
                }
                r -= s[i].a;
                i++;
            }
            if(r == 0){
                j--;
                continue;
            }
            if(r < s[j].a){
                if(s[i].c != s[j].c){
                    cnt += r;
                }
                l = s[i].a - r;
                r = 0;
                j--;
            }
        }else if(l == 0 && r == 0){
            if(s[i].a > s[j].a){
                l = s[i].a - s[j].a;
                if(s[i].c != s[j].c){
                    cnt += s[j].a;
                }
                j++;
            }else if(s[j].a > s[i].a){
                r = s[j].a - s[i].a;
                if(s[j].c != s[i].c){
                    cnt += s[i].a;
                }
                i++;
            }else if(s[i].a == s[j].a){
                if(s[i].c != s[j].c){
                    cnt += s[i].a;
                }
                i++, j--;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}