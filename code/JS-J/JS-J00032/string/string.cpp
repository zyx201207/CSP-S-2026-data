#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n = 0;
long long len = 0;
struct node{
    long long a;
    char c;
}A[maxn];
long long check (){
    long long ans = 0;
    long long t = len,top = 0;
    len -= len / 2;
    while (len > 0){
        len -= A[++top].a;
    }
    int mid = top,j = n;
    A[mid].a += len;
    for (int i = 1;i <= mid;i++){
        int shu = A[i].a;
        while(shu > 0){
            if (A[j].a > shu){
                if (A[j].c != A[i].c) ans += shu;
                A[j].a -= shu;
                break;
            }
            else if (A[j].a == shu){
                if (A[j].c != A[i].c) ans += shu;
                j--;
                break;
            }
            else{
                if (A[j].c != A[i].c) ans += A[j].a;
                shu -= A[j].c;
                j--;
            }
        }
    }
    return ans;
}
int main (){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    memset(A,0,sizeof(A));
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> A[i].a >> A[i].c;
        len += A[i].a;
    }
    long long shu = check();
    if (shu != 1) cout << shu;
    else cout << shu + 1;
    return 0;
}

