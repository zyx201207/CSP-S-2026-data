#include <iostream>

using namespace std;

int main()
{freopen("travel3.in","r",stdin);
freopen("travel3.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int flag=1;
    for(int i=0;i<=1;i++){
        if(c1[i]-'0'!=c2[i]-'0'){
            flag=0;
        }
    }
    if(flag==0){
        cout<<"0000";
        return 0;

    }

    else{
            cout<<"1";
            int flag2=1;
        for(int i=0;i<=1;i++){
            if(s1[i]!=s2[i]){
                flag2=0;
            }
        }

        if(flag2==0){
            cout<<"000";
        }
        else{
            cout<<flag2;
            int flag3=1,flag4=1;
            if(s1[2]-'0'=='A'-'0'||s1[2]-'0'=='B'-'0'||s1[2]-'0'=='C'-'0'){
                flag3=0;
            }
            if(s2[2]-'0'=='A'-'0'||s2[2]-'0'=='B'-'0'||s2[2]-'0'=='C'-'0'){
                flag4=0;
            }
               if(flag3==flag4){
                cout<<"1";
                if(s1[2]-'0'=='D'-'0'&&s2[2]-'0'=='F'-'0'){
                    cout<<"1";
                }
                else{
                    if(s1[2]-'0'=='C'-'0'&&s2[2]-'0'=='D'-'0'){
                        cout<<"0";
                                            }
                                            else{
                                                if(s1[2]-'0'==s2[2]-'0'+1||s1[2]-'0'==s2[2]-'0'-1){
                                                    cout<<"1";
                                                }
                                                else{
                                                    cout<<"0";
                                                }
                                            }
                }
            }
            else{
                cout<<"00";
            }
        }


}
cout<<endl;
 return 0;
}
