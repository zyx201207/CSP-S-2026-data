#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a,b,c,d,ans;
    cin>>a>>b>>c>>d;

    if(a[0]==c[0]&&a[1]==c[1]){
        ans+="1";
        if(b[0]==d[0]&&b[1]==d[1]){
            ans+="1";
            if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
                if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
                    ans+="1";
                    if(b[2]=='B'||d[2]=='B'){
                        ans+="1";
                    }
                    else{
                        ans+="0";
                    }
                }
                else{
                    ans+="00";
                }
            }
            if(b[2]=='D'||b[2]=='F'){
                if(d[2]=='D'||d[2]=='F'){
                    ans+="11";
                }
                else{
                    ans+="00";
                }
            }
        }
        else{
            ans+="000";
        }
    }
    else{
        ans+="0000";
    }

    cout<<ans;

    fclose(stdin);
    fclose(stdout);

    return 0;

}
