#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in",stdin);
    freopen("travel.out",stdout);
    string r_c,x_c,r_z,x_z;
    cin>>r_c>>r_z>>x_c>>x_z;
    if(r_c==x_c){
        cout<<1;
        if(r_z[1]==x_z[1]&&r_z[0]==x_z[0]){
            cout<<1;
            if(((r_z[2]=='A'||r_z[2]=='B'||r_z[2]=='C')&&(x_z[2]=='A'||x_z[2]=='B'||x_z[2]=='C'))||((r_z[2]=='F'&&x_z[2]=='D')||(r_z[2]=='D'&&r_z[2]=='F'))){
                cout<<1;
                if(((r_z[2]=='A'&&x_z[2]=='B')||(r_z[2]=='B'&&x_z[2]=='A'))||((r_z[2]=='B'&&x_z[2]=='C')||(r_z[2]=='C'&&x_z[2]=='B'))||((r_z[2]=='D'&&x_z[2]=='F')||(r_z[2]=='F'&&x_z[2]=='D')))
                    cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
