#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long a[N],ans;
struct node{
    char ch;
    long long num;
}l,r;
int n;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n ;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
    }
    int i = 1,j = n;
    r.ch = c[n];
    r.num = a[n];
    l.ch = c[1];
    l.num = a[1];
    ans = 0;
    while(i < j){


        int xiao = min(l.num,r.num);
        if(l.ch != r.ch)ans += xiao;
        l.num -= xiao;
        r.num -= xiao;

        if(l.num == 0){
            i++;
            l.ch = c[i];
            l.num = a[i];
        }
        if(r.num == 0){
            j--;
            r.ch = c[j];
            r.num = a[j];

        }
    }
    cout << ans;
    return 0;
}
