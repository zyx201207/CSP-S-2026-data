#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char seat_cols[10] = "ABC\0DF";

int isnearby(char a,char b) {
    int idxa,idxb;
    for (int i=0;i<=5;++i) {
        if (seat_cols[i]==a) {
            idxa = i;
            break;
        }
    }
    for (int i=0;i<=5;++i) {
        if (seat_cols[i]==b) {
            idxb = i;
            break;
        }
    }
#ifdef INDBG
    printf("\na: %c, b: %c, idxa: %d, idxb: %d\n",a,b,idxa,idxb);
#endif //INDBG
    return (abs(idxa-idxb) == 1);
}

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;

    cin >> c1 >> s1 >> c2 >> s2;

    if (c1 == c2) {//同一节车厢
        cout << "1";
        if (s1[0] == s2[0] && s1[1] == s2[1]) {//同一排
            cout << "1";
            if ((s1[2] <= 'C' && s2[2] <= 'C') || ('D' <= s1[2] && 'D' <= s2[2])) {//同一侧
                cout << "1";
                if (isnearby(s1[2],s2[2])) {//isnearby
                    cout << "1";
                }else cout << "0";
            } else {
                cout << "00";
            }
        } else {
            cout << "000";
        }
    } else {
        cout << "0000";
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
