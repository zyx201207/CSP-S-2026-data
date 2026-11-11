#include<bits/stdc++.h>
using namespace std;
char a[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[5],c2[5],c3[5],c4[5];
    cin>>c1>>c2>>c3>>c4;
    if(c1[0]==c3[0]&&c1[1]==c3[1])a[1]='1';
    else {a[1]='0';cout<<"0000";return 0;}
    for(int i=0;i<3;i++){
        if(c2[i]>='0'&&c2[i]<='9'&&c4[i]>='0'&&c4[i]<='9'){
            if(c2[i]!=c4[i]){
                a[2]='0';
                cout<<"1000";
                return 0;
            }
        }
        else{
            if((c2[i]<='C'&&c4[i]<='C')){
                a[3]='1';
                if(c2[i]-1==c4[i]||c4[i]-1==c2[i]){a[4]='1';}
                else{
				    a[4]='0';
				    cout<<"1110";
				    return 0;
			    }
            }
            else if(c2[1]>'C'&&c4[i]>'C')a[3]='1',a[4]='1';
            else {
			a[3]='0';
			cout<<"1100";
			return 0;
            }
        }
    }
    if(a[2]!='0')a[2]='1';
    if(a[3]!='0')a[3]='1';
    if(a[4]!='0')a[4]='1';
    for(int i=1;i<=4;i++)cout<<a[i];
    return 0;
}
