#include<bits/stdc++.h>
using namespace std;
char c1a,c1b,g1a,g1b,g1c,c2a,c2b,g2a,g2b,g2c;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>c1a>>c1b>>g1a>>g1b>>g1c>>c2a>>c2b>>g2a>>g2b>>g2c;
	int a=g1c-'A'+1,b=g2c-'A'+1;
	cout<<a<<' '<<b<<endl;
    if(c1a==c2a&&c1b==c2b){
        cout<<'1';
        if(g1a==g2a&&g1b==g2b){
            cout<<'1';
            if((a==4&&b==6)||(a==6&&b==4))
                cout<<"11";
            else{
                if(a>=1&&a<=3&&b>=1&&b<=3){
                    cout<<'1';
                    int t=abs(a-b);
                    if(t==1)
                        cout<<'1';
                    else
                        cout<<'0';
                }
                else
                    cout<<"00";
            }
        }
        else
            cout<<"000";
    }
    else
        cout<<"0000";
	return 0;
}
