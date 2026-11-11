#include<bits/stdc++.h>
using namespace std;
string a,b;
char aa1,aa2,aa3,bb1,bb2,bb3;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>aa1>>aa2>>aa3;
    cin>>b>>bb1>>bb2>>bb3;
    if(b==a){
        cout<<1;
        if(aa1==bb1&&aa2==bb2){
            cout<<1;
            if((aa3=='A'&&(bb3=='B'||bb3=='C'))||(aa3=='B'&&(bb3=='A'||bb3=='C'))||(aa3=='C'&&(bb3=='A'||bb3=='B'))||(aa3=='F'&&bb3=='D')||(aa3=='D'&&bb3=='F')){
                cout<<1;
                if((aa3=='A'&&bb3=='B')||(aa3=='B'&&bb3=='C')||(aa3=='B'&&bb3=='A')||(aa3=='C'&&bb3=='B')||(aa3=='F'&&bb3=='D')||(aa3=='D'&&bb3=='F')) cout<<1;
                    else cout<<0;
            }
            else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
