#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,x,y;
    cin>>a>>b>>x>>y;
    int w=(a[0]-'0')*10+a[1];
    int z=(x[0]-'0')*10+x[1];
    if(w==z){
        cout<<1;
        int t=(b[0]-'0')*10+b[1];
        int p=(y[0]-'0')*10+y[1];
        if(t==p){
            cout<<1;
            int h=b[2]-'A';
            int l=y[2]-'A';
            if((h<=2&&l<=2)||(h>2&&h<=4&&l>2&&l<=4)){
                cout<<1;
                if(abs(h-l)==1)
                    cout<<1;
                else
                    cout<<0;
            }else{
                cout<<"00";
            }

        }else{
            cout<<"000";
        }

    }else{
        cout<<"0000";
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}

