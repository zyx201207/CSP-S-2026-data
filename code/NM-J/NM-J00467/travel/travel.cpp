#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout):
    string c1,s1,c2,s2;
    int a,b,c,d;
    cin>>c1>>s1>>c2>>s2;
    a = s1[2];
    b = s2[2];
    c = 'C';
    d = 'D';
    if(c1 == c2){
        cout<<1;
        if(s1[0] == s2[0] && s1[1] == s2[1]){
        cout<<1;
        }else{
        cout<<0;
        }
        if((s1[0] == s2[0] && s1[1] == s2[1]) && ((a <= c && b <= c) || (a >= d && b >= d))){
            cout<<1;
        }else{
            cout<<0;
        }
        if((s1[0] == s2[0] && s1[1] == s2[1]) && ((a <= c && b <= c) || (a >= d && b >= d)) &&  (a + 1 == b || b + 1 == a)){
            if(((a != c && b == d) || (a == d || b != c)) || ((a == c && b != d) || (b == c && a != d))){
                cout<<1;
               }
        }else{
            cout<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
    }


    return 0;
}
