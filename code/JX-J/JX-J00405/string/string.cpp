#include<bits/stdc++.h>
using namespace std;

int n,a,sum,ans;
char c;
string d;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a;
        cin >> c;
        ans += a;
        for(int j = 0 ; j < a; j++){
            d = d+char(c);
        }
    }
    if(ans%2 == 0){
        for(int i = 0 ; i <= ans/2 ; i++){
            if(d[i] != d[ans-i-1]){
                sum++;
            }
        }
    }else{
        for(int i = 0 ; i < ans/2 ; i++){
            if(d[i] != d[ans-i-1]){
                sum++;
            }
        }
    }

    cout << sum;
    return 0;
}
