#include <bits/stdc++.h>
using namespace std;

struct lists{
    long long numbers;char tchar;
};
vector<lists> chars;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n; cin >> n;
    for (long long i = 0; i < n; ++i){
        long long a;
        char b;
        cin  >> a >> b;
        if (i > 0){
            if (chars[i-1].tchar == b){
                chars[i-1] = {chars[i-1].numbers + a, b};
                n --;
                i --;
            }
            else{
                chars.push_back({a, b});
            }
        }
        else{
            chars.push_back({a,b});
        }
    }
    //----------
    long long cnt = 0;
    int leftt = 0;
    int rightt = chars.size() - 1;
    while ((leftt < rightt) && (chars.size() > 1)){
        auto left = chars[leftt];
        auto right = chars[rightt];
        if (left.numbers == right.numbers){
            if (left.tchar == right.tchar){
                leftt++;
                rightt--;
                continue;
            }
            else{
                cnt += left.numbers;
                leftt++;
                rightt--;
                continue;
            }
        }
        else{
            if (left.numbers > right.numbers){
                chars[leftt] = {left.numbers - right.numbers,left.tchar};
                if (left.tchar == right.tchar){
                    rightt--;
                }
                else{
                    cnt += right.numbers;
                    rightt--;
                }
            }
            if (left.numbers < right.numbers){
                chars[rightt] = {right.numbers - left.numbers,right.tchar};
                if (left.tchar == right.tchar){
                    leftt++;
                }
                else{
                    cnt += left.numbers;
                    leftt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
