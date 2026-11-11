#include <bits/stdc++.h>
using namespace std;
string a = "1111";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if (c1.size()!=c2.size()){
        a[0] = '0';
        a[1] = '0';
        a[2] = '0';
        a[3] = '0';
        cout<<a;
        return 0;
    }
    else{
        for (int i = 1;i<c1.size();i++){
            if (c1[i]!=c2[i]){
                a[0] = '0';
                a[1] = '0';
                a[2] = '0';
                a[3] = '0';
                cout<<a;
                return 0;
            }

        }
    }
    for (int i = 0;i<=1;i++){
        if (s1[i]!=s2[i]){
                a[1] = '0';
                a[2] = '0';
                a[3] = '0';
                cout<<a;
                return 0;

        }
    }
    if ((s1[2] == 'A' ||s1[2] == 'B'||s1[2] == 'C') && (s2[2] == 'A'||s2[2] == 'B'||s2[2] == 'C')){
        a[2] = '1';
        if ((s1[2] == 'A' && s2[2] == 'C') || (s2[2] == 'A'&&s1[2] == 'C')){
            a[3] = '0';
        }
        cout<<a;
    }
    else if ((s1[2] == 'D' ||s1[2] == 'F') && (s2[2] == 'D'||s2[2] == 'F')){
        cout<<"1111";
    }

    cout<<a;
    return 0;
}
