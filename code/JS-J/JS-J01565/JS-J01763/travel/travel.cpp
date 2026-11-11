#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    char a=s1[0],a1=s1[1];
    char b=s2[0],b1=s2[1];
    char m=s1[2],n=s2[2];
    if(c1==c2){
        cout << 1;
        if(a==b&&a1==b1){
            cout << 1;
            if(('A'<=m<='C'&&'A'<=n<='C')||('D'<=m<='E'&&'D'<=n<='E')){
                cout << 1;
                int num=m-n;
                if(abs(num)==1){
                    cout << 1;
                }
                else {
                    cout << 0;
                }
            }
            else{
                cout << 0 << 0;
            }
        }
        else{
            cout << 0 << 0 << 0;
        }
    }
    else{
        cout << 0 << 0 << 0 << 0;
    }


    return 0;

}
