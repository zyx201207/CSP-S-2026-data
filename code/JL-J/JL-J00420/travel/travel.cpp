#include<bits/stdc++.h>
using namespace std;
int main(){
//02 01D 02 01F
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a;
    getline(cin,a);
    int u=3;
  // for(int i=0;i<a.length();i++){
   //    cout << a[i] << ' ' << i;
  //     cout << endl;
  //  }
  //  cout << a[0] << ' ' << a[7] << endl;
  //  cout << a[1] <<' ' << a[8] << endl;
    if(a[0]==a[7]&&a[1]==a[8]){
    cout << 1;
    u--;
    if(a[3]==a[10]&&a[4]==a[11]){
        cout << 1;
        u--;
        bool p=0;
        bool q=0;
        if(a[5]=='A'||a[5]=='B'||a[5]=='C')
            p=0;
        else
            p=1;
        if(a[12]=='A'||a[12]=='B'||a[12]=='C')
            q=0;
        else
            q=1;
         //   cout << "       " << p << ' ' << q << endl;
            if(q==p){
                    cout << 1;
                u--;
            if(a[5]=='D'&&a[12]=='F'){
                cout << 1;
                return 0;
            }
            if(a[5]=='F'&&a[12]=='D'){
                cout << 1;
                return 0;
            }
                int g=abs(a[5]-a[12]);


                if(g==1)
                    cout << 1;
                else
                    cout << 0;
            }
            else{
                cout << 0;
                for(int i=0;i<u;i++)
                    cout << 0;
            }
    }
    else{
        cout << 0;
        for(int i=0;i<u;i++)
            cout << 0;
    }
    }


    else{
        cout << 0;
    for(int i=0;i<u;i++)
    cout << 0;
    }


    return 0;
}
