#include<bits/stdc++.h>
using namespace std;
string s = "";
long long cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++){
        long long a;
        scanf("%lld",&a);
        char c;
        cin >> c;
        for(int j = 1 ; j <= a ; j++){
            s += c;
        }
    }
    long long sl = s.size();
    long long mid = sl/2;
    long long l , r;
    l = mid;
    if(sl % 2 == 0){
        r = l+1;
    }
    else{
        r = l+2;
    }
    while(l > 0 && l <= sl && r > 0 && r <= sl){
        if(s[l-1] != s[r-1]){
            cnt++;
        }
        l--;
        r++;
    }
    printf("%lld",cnt);
    return 0;
}
