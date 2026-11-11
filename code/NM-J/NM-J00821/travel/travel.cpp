#include <iostream>
#include<string>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool a[4];
    for(int i=0;i<4;i++){
        a[i]=0;
    }
    int a1;
    int b1;
    string a2;
    string b2;
    cin>>a1;
    cin>>a2;
    cin>>b1;
    cin>>b2;
    if(a1==b1){
        a[0]=1;
        if(a2[0]==b2[0]){
            if(a2[1]==b2[1]){
                a[1]=1;
                if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'){
                    if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
                        a[2]=1;
                        if(a2[2]=='A'){
                            if(b2[2]=='B'){
                                a[3]=1;
                            }
                        }
                        if(a2[2]=='B'){
                            if(b2[2]=='C'){
                                a[3]=1;
                            }
                        }
                        if(a2[2]=='B'){
                            if(b2[2]=='A'){
                                a[3]=1;
                            }
                        }
                        if(a2[2]=='C'){
                            if(b2[2]=='B'){
                                a[3]=1;
                            }
                        }
                    }
                }
                if(a2[2]=='D'||a2[2]=='F'){
                    if(b2[2]=='D'||b2[2]=='F'){
                        a[2]=1;
                        if(a2[2]=='D'){
                            if(b2[2]=='F'){
                                a[3]=1;
                            }
                        }
                        if(a2[2]=='F'){
                            if(b2[2]=='D'){
                                a[3]=1;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
