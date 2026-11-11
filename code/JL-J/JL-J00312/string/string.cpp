#include <iostream>
using namespace std;
struct q{
    int num;
    char crt;
};
q inp[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    for(int i = 1;i <= n;i++){
       cin >> inp[i].num >> inp[i].crt;
    }
    long long l = 1,r = n;
    long long ans = 0;
    while(l < r){
        if(inp[l].crt != inp[r].crt){
            if(inp[l].num < inp[r].num){
                ans += inp[l].num;
                inp[r].num -= inp[l].num;
                l++;
            }
            else if(inp[l].num > inp[r].num){
                ans += inp[r].num;
                inp[l].num -= inp[r].num;
                r--;
            }
            else{
                ans += inp[r].num;
                l++;
                r--;
            }
        }
        else{
             if(inp[l].num < inp[r].num){
                inp[r].num -= inp[l].num;
                l++;
             }
            else if(inp[l].num > inp[r].num){
                 inp[l].num -= inp[r].num;
                 r--;
            }
            else{
                l++;
                r--;
            }
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
