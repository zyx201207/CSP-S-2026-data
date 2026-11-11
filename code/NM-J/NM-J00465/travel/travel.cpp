#include <bits/stdc++.h>
using namespace std;
char s;
int a[10005],b[100005];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> s; a[1]=s-'0';
    cin >> s; a[1]=a[1]*10+(s-'0');
    cin >> s; a[2]=s-'0';
    cin >> s; a[2]=a[2]*10+(s-'0');
    cin >> s; if(s=='F') s='E';a[3]=s-'A'+1;
    cin >> s; b[1]=s-'0';
    cin >> s; b[1]=b[1]*10+(s-'0');
    cin >> s; b[2]=s-'0';
    cin >> s; b[2]=b[2]*10+(s-'0');
    cin >> s; if(s=='F') s='E';b[3]=s-'A'+1;
    if(a[1]==b[1]){
        cout << 1;
        if(a[2]==b[2]){
            cout <<1;
            if(a[3]<=3&&b[3]<=3||a[3]>=4&&b[3]>=4){
                cout << 1;
                if(a[3]-b[3]==1||b[3]-a[3]==1) cout << 1;
                else cout << 0;
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
