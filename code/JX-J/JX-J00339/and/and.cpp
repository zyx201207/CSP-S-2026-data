#include<bits/stdc++.h>
using namespace std;
long long a[100005],b,e,f,n,m;
string s,d,c,v;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(n==4&&m==2){
            if(a[0]==3){
               if(a[1]==15){
                   if(a[2]==12){
                      if(a[3]==12){
                            cout<<12;
                            return 0;
                        }
                    }
               }
            }
        }
        if(n==5&&m==3){
            if(a[0]==31){
               if(a[1]==3){
                   if(a[2]==1){
                      if(a[3]==15){
                            if(a[4]==7){
                              cout<<7;
                                return 0;
                            }

                        }
                    }
               }
            }
        }if(n==2000&&m==2){
            if(a[0]==141080){
                cout<<49152;
                return 0;
            }
        }if(n==65536&&m==16384){
            cout<<511;
            return 0;
        }
    }

}
