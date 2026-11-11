#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string chexiang_a,zuowei_a,chexiang_b,zuowei_b;
    cin>>chexiang_a>>zuowei_a>>chexiang_b>>zuowei_b;
    if(chexiang_a==chexiang_b)
    {
        cout<<"1";
        if(zuowei_a[0]==zuowei_b[0]&&zuowei_a[1]==zuowei_b[1])
        {
            cout<<"1";
            if(zuowei_a[2]=='A'||zuowei_a[2]=='B'||zuowei_a[2]=='C')
            {
                if(zuowei_b[2]=='A'||zuowei_b[2]=='B'||zuowei_b[2]=='C')
                {
                    cout<<"1";
                    if(zuowei_a[2]+1==zuowei_b[2]||zuowei_b[2]+1==zuowei_a[2])
                    {
                        cout<<"1";
                    }
                    else{
                        cout<<"0";
                    }
                }
            }
            else if(zuowei_a[2]=='D'||zuowei_a[2]=='F'){
                if(zuowei_b[2]=='D'||zuowei_b[2]=='F')
                {
                    cout<<"1";
                    if(zuowei_a[2]+1==zuowei_b[2]||zuowei_b[2]+1==zuowei_a[2])
                    {
                        cout<<"1";
                    }
                    else{
                        cout<<"0";
                    }
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}