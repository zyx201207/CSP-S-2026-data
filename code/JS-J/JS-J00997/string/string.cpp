#include<bits/stdc++.h>
using namespace std;

int n,a;
char c;
int bug,sum;
char s[2000000000];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a >> c;
        for(int k = 0;k < a;k++){
            s[sum] = c;
            sum++;
        }
    }
    for(int i = 0;i < sum / 2;i++){
        if(s[i] != s[sum - i - 1]){
            bug++;
        }
    }
    cout << bug;
    cout << endl;

    return 0;
}
