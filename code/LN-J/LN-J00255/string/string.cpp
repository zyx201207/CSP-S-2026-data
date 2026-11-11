#include<iostream>
using namespace std;
int n;
long long a,asum,ans;
string s,sym;
int main(){
    freopen("string.in","r",stdin);
    freopen("string,out","w",stdout);

    cin >> n;
    if (n <= 1){
        cout << 0;
        return 0;
    }
    for (int i = 1;i<=n;i++){
        cin >> a >> sym;
        asum += a;
        while(a--){
            s += sym;
        }

    }
    if (asum <= 1){
        cout << 0;

    }
    else{
        for (int i = 0;i<(asum / 2);i++){
            if (s[i] != s[asum - 1 - i]){
                ans++;
            }
        }
        cout <<ans;
    }




    return 0;
}
