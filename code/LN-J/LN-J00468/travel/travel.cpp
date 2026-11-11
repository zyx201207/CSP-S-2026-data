#include<bits/stdc++.h>
using namespace std;

#define int long long
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<3)+(x<<1)+ch-'0';
        ch = getchar();
    }
    return x*f;
}

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >>s2;
    if(c1 != c2)
        cout << "0000";
    else{
        if(s1[0]!=s2[0]||s1[1]!=s2[1])
            cout << "1000";
        else{
            if(s1[2]<='C'&&s2[2]<='C'||(s1[2]>='D'&&s2[2]>='D')){
                if(s1[2]=='A'&&s2[2]=='C'||(s1[2]=='C'&&s2[2]=='A'))cout << "1110";
                else cout << "1111";
            }
            else cout << "1100";
        }


    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
