#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c,n,m;
    char b,d;
    cin >> a>>n>>b>>c>>m>>d;
    if(a==c){
        cout <<"1";
        if(n==m){
            cout << "1";
            if(b=='A'&&d=='B'||b=='B'&&d=='A'||b=='A'&&d=='C'||b=='C'&&d=='A'||b=='C'&&d=='B'||b=='B'&&d=='C'||b=='D'&&d=='F'||b=='F'&&d=='D'){
                cout << "1";
                if(b=='A'&&d=='B'||b=='B'&&d=='A'||b=='C'&&d=='B'||b=='B'&&d=='C'||b=='D'&&d=='F'||b=='F'&&d=='D'){
                    cout <<"1";
                }else{
                    cout << "0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout <<"000";
        }
    }else{
        cout << "0000";
    }
    return 0;
}
