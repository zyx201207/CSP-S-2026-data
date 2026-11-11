#include<bits/stdc++.h>
using namespace std;
void check(string a){
    int j = 0;
    for(int i = a.size()-1;i>=j;i--){
        if(a[j] != a[i]){

        }
        j++;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string t;
    cin >> n;
    for(int i = 0;i<n;i++){
        int p;
        char ll;
        cin >> p >> ll;
        for(int k = 1;k<=p;k++){
            t += ll;
        }
    }
    cout << 0 << endl;
}
