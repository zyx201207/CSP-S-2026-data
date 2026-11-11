#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string pm[6] = {0};
for (int i = 0;i <= 3;i++){
    cin >> pm[i];
}

if (pm[0] == pm [2]){
    cout << 1111;
}
else {
    cout << 0000;
}

fclose(stdin);
fclose(stdout);
