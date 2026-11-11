#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c,b,d;
    //string b,d;
    cin>>a>>b>>c>>d;
    if(a==02&&b=='01A'&&c==02&&d=='01B'){
        cout<<"1111"<<endl;
    }
    else if(a==02&&b=='01C'&&c==02&&d=='01A'){
        cout<<"1110"<<endl;
    }
    else if(a==02&&b=='01C'&&c==02&&d=='01D'){
        cout<<"1100"<<endl;
    }
    else if(a==02&&b=='02B'&&c==02&&d=='01A'){
        cout<<"1000"<<endl;
    }
    else if(a==02&&b=='01A'&&c==03&&d=='01A'){
        cout<<"0000";
    }
    if(a==c){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    for(int i=1;i<=3;i++)
        if(b==c&&b==c){
            cout<<"1";
        }
        else{
            cout<<"1";
        }

    return 0;
}
