#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
int n;
struct pla{
    long a;
    char c;
} sum[MAX];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    string s = "";
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> sum[i].a >> sum[i].c;
        for(long j = 1;j <= sum[i].a;j++) s += sum[i].c;
    }
    bool flag = true;
    for(int i = 2;i <= n;i++){
        if(sum[i].c != sum[i - 1].c){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << 0;
        return 0;
    }
    long long sum = 0;
    for(long long i = 0;i <= s.size() / 2 + 1;i++){
        if(s[i] != s[s.size() - i - 1]) sum++;
    }
    cout << sum;


    return 0;
}

