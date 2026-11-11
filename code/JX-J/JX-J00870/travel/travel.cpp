#include<bits/stdc++.h>
using namespace std;
int k[10]={0,1,1,1,2,0,2};
int k1[10]={0,1,2,3,5,0,6};
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2) cout << 1;
    else cout << 0;
    int n1=(s1[0]-'0')*10+(s1[1]-'0');
    int n2=(s2[0]-'0')*10+(s2[1]-'0');
    if(c1==c2&&n1==n2) cout << 1;
    else cout << 0;
    int p1=s1[2]-'A'+1;
    int p2=s2[2]-'A'+1;
    if(c1==c2&&n1==n2) {
        if(k[p1]==k[p2]) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    else {
        cout << 0;
    }
    if(c1==c2&&n1==n2&&(k1[p1]-k1[p2]==1||k1[p1]-k1[p2]==-1)) {
        cout << 1;
    }
    else {
        cout << 0;
    }
    return 0;
}