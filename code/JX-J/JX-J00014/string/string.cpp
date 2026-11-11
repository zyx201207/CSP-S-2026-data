#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
    int a;
    char c;
};

const int N = 2e7 + 6;
node arr[N];
char s[N];

int n;

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;

    int len = 0;

    for(int i = 1;i <= n;i ++){
        cin >> arr[i].a >> arr[i].c;

        for(int j = 1;j <= arr[i].a;j ++) s[len + j] = arr[i].c;
        
        len += arr[i].a;
    }

    int cnt = 0;
    for(int i = 1;i <= len / 2;i ++){
        if(s[i] != s[len - i + 1]) cnt ++;
    }
    
    cout << cnt;
    return 0;
}
// #include<bits/stdc++.h>
// #define int long long
// using namespace std;

// struct node{
//     int a;
//     char c;
// };

// const int N = 2e5 + 6;
// node arr[N];
// vector<node> s(N);

// int n;

// signed main(){
//     cin >> n;

//     int len = 0;

//     for(int i = 1;i <= n;i ++){
//         cin >> arr[i].a >> arr[i].c;
//         len += arr[i].a;
//     }

//     int x = len / 2;

//     int p = 1;
//     s[p].a = arr[p].a,s[p].c = arr[p].c;
    
//     int t = 0;
//     bool flag = false;
//     for(int i = 2;i <= n;i ++){
//         t += arr[i].a;
        
//         if(t > x && !flag){
//             flag = true;
//             s[p].a += x - t + arr[i].a;
//             p ++;
//             s[p].a = t - x;
//             if(len & 1) s[p].a --;
//         }

//         if(arr[i].c == arr[i - 1].c) s[p].a += arr[i].a;
//         else{
//             p ++;
//             s[p].a = arr[i].a;
//             s[p].c = arr[i].c;
//         }
//     }

//     if(p == 2){
//         cout << 0;
//         return 0;
//     }

//     int l = 1,r = p;
//     int s1 = 0,s2 = 0;
//     int cnt = 0;
//     while(l < r){
//         if(s1 + s2 == len) break;

//         if(s[l].c == s[r].c){
//             cnt += abs(s[r].a - s[l].a);
//             s1 += s[l].a;
//             s2 += s[r].a;
//             l ++;
//             r --;
//         }
//         else{
//             if(s[r].a > s[l].a){
//                 cnt += s[r].a - s[l].a;
//                 s1 += s[l].a,s2 += s[l].a;
//                 l ++;
//                 s[r].a -= s[l].a;
//             }
//             else{
//                 cnt += s[l].a - s[r].a;
//                 s1 += s[r].a,s2 += s[r].a;
//                 r --;
//                 s[l].a -= s[r].a;
//             }
//         }
        
//     }

//     cout << cnt;
//     return 0;
// }