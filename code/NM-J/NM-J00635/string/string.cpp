#include <iostream>
#include <cstring>
using namespace std;
long long a[10000111];
string c[100111011];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i; i<=n; i++){
        cin >> a[i] >> c[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
