#include<bits/stdc++.h>
using namespace std;
int ans1,ans2,ans3,ans4;
char a[5],b[5],c[5],d[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a[0]==c[0]&&a[1]==c[1]){
        ans1=1;
        if(b[0]==d[0]&&b[1]==d[1]){
            ans2=1;
            if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F')){
                ans3=1;
                if(abs(b[2]-d[2])==1){
                    ans4=1;
                }
            }

        }

    }
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
