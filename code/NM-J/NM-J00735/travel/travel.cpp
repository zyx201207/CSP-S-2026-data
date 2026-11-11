#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r,r1;
    string x,x1;
    cin>>r>>r1;
    cin>>x>>x1;
    if (r == x){
        cout << "1";
        if (r1 >="0"&& r1 <="9"){
            if(x1 >="0"&& x1 <="9"){
                if (r1[0]!=x1[0]){
                    cout << "000";
                }else{
                    if (r1[1] == x1[1]){
                        cout << "1";
                        if (r1[2] >= "D" && r1[2] <= "F")
                        {
                            if (x1[2] >= "D" && x1[2] <= "F"){
                                if (x1[2] != r1[2]){
                                    cout<<"1";
                                }else{
                                    cout<<"0";
                                }
                            }
                        }else{
                            cout<<"0";
                            if(r1[2] >= "A" && r1[2]<="C"){
                                if (r1[2] == "A"){
                                    if (x1[2] != "C"){
                                        cout<<"1";
                                    }else{
                                        cout<<"0";
                                    }
                                }else if(r1[2] == "B"){
                                    if (x1[2] != "A" && x1[2] != "C"){
                                        cout<<"1";
                                    }else{
                                        cout<<"0";
                                    }
                                }else if(r1[2] == "C"){
                                    if (x1[2] != "B"){
                                        cout<<"1";
                                    }else{
                                        cout<<"0";
                                    }
                                }
                            }else{
                                cout <<"0";
                            }
                        }
                    }else{
                        cout << "0";
                    }
            }
        }
    }
    }else{
        cout << "0000";
        }
    return 0;
}
