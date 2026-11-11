#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a;
    for(int i=1;i<=6;i++){
        cin>>a[i];
    }
    for(int i=1;i<=4;i++){
        if(a[1]==a[4]){
            cout<<"1";
        }else{
            cout<<"0";
        }
        if(a[1]==a[4]&&a[2]==a[5]){
            cout<<"1";
        }else{
            cout<<"0";
        }
        if(a[1]==a[4]&&a[2]==a[5]){
            if(a[3]==A||a[3]==B||a[3]==C){
                if(a[6]==A||a[6]==B||a[6]==C){
                    cout<<"1";
                }
                if(a[6]==D||A[6]==F){
                    cout<<"0";
                }
            }
            if(a[3]==D||A[3]==F){
                if(a[6]==D||A[6]==F){
                    cout<<"1";
                }
                if(a[6]==A||a[6]==B||a[6]==C){
                    cout<<"0";
                }
            }
        }
        if(a[1]==a[4]&&a[2]==a[5]){
            if(a[3]==A||a[3]==B||a[3]==C){
                if(a[6]==A||a[6]==B||a[6]==C){
                    if(a[3]==A&&a[6]==B){
                        cout<<"1";
                    }
                    if(a[3]==B&&a[6]==C){
                        cout<<"1";
                    }
                    if(a[6]==A&&a[3]==B){
                        cout<<"1";
                    }
                    if(a[6]==B&&a[3]==C){
                        cout<<"1";
                    }
                    if(a[6]==A&&a[3]==C){
                        cout<<"0";
                        return 0;
                    }
                    if(a[3]==A&&a[6]==C){
                        cout<<"0";
                        return 0;
                    }
                }else{
                    cout<<"0"
                    return 0;
                }
            }
            if(a[3]==D||A[6]==F){
                if(a[6]==D||A[6]==F){
                    cout<<"1";
                }
                if(a[6]==A||a[6]==B||a[6]==C){
                    cout<<"0";
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
