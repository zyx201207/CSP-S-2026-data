#include <bits/stdc++.h>
using namespace std;
int n[25];
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>n[i];
    }
    if(a==1){
        cout<<n[1];
    }
    else if(a==2){
        if(b==1)cout<<max(n[1],n[2]);
        else cout<<(n[1]&n[2]);
    }
    else if(a==3){
        if(b==1)cout<<max(n[1],max(n[2],n[3]));
        else if(b==2)cout<<max(n[1]&n[2],max(n[1]&n[3],n[2]&n[3]));
        else cout<<(n[1]&n[2]&n[3]);
    }
    else if(a==4){
        if(b==1)cout<<max(n[1],max(n[2],max(n[3],n[4])));
        else if(b==2)cout<<max(n[1]&n[2],max(n[1]&n[3],max(n[1]&n[4],max(n[2]&n[3],max(n[2]&n[4],n[3]&n[4])))));
        else if(b==3)cout<<max(n[1]&n[2]&n[3],max(n[1]&n[2]&n[4],max(n[1]&n[3]&n[4],n[2]&n[3]&n[4])));
        else cout<<(n[1]&n[2]&n[3]&n[4]);
    }
    else if(a==5){
        if(b==1)cout<<max(n[1],max(n[2],max(n[3],max(n[4],n[5]))));
        else if(b==2)cout<<max(n[1]&n[2],max(n[1]&n[3],max(n[1]&n[4],max(n[2]&n[3],max(n[2]&n[4],max(n[1]&n[5],max(n[2]&n[5],max(n[3]&n[5],max(n[3]&n[4],n[4]&n[5])))))))));
        else if(b==3)cout<<max(n[1]&n[2]&n[3],max(n[1]&n[2]&n[4],max(n[1]&n[2]&n[5],max(n[1]&n[3]&n[4],max(n[1]&n[3]&n[5],max(n[1]&n[4]&n[5],max(n[2]&n[3]&n[4],max(n[2]&n[3]&n[5],max(n[2]&n[4]&n[5],n[3]&n[4]&n[5])))))))));
        else if(b==4)cout<<max(n[1]&n[2]&n[3]&n[4],max(n[1]&n[2]&n[3]&n[5],max(n[1]&n[2]&n[4]&n[5],max(n[1]&n[3]&n[4]&n[5],n[2]&n[3]&n[4]&n[5]))));
        else cout<<(n[1]&n[2]&n[3]&n[4]&n[5]);
    }
    else if(a==6){
        if(b==1)cout<<max(n[1],max(n[2],max(n[3],max(n[4],max(n[5],n[6])))));
        else if(b==2)cout<<max(n[1]&n[2],max(n[1]&n[3],max(n[1]&n[4],max(n[2]&n[3],max(n[2]&n[4],max(n[1]&n[5],max(n[2]&n[5],max(n[3]&n[5],max(n[3]&n[4],max(n[4]&n[5],max(n[1]&n[6],max(n[2]&n[6],max(n[3]&n[6],max(n[4]&n[6],n[5]&n[6]))))))))))))));
        else if(b==3)cout<<max(n[1]&n[2]&n[3],max(n[1]&n[2]&n[4],max(n[1]&n[2]&n[5],max(n[1]&n[2]&n[6],max(n[1]&n[3]&n[4],max(n[1]&n[3]&n[5],max(n[1]&n[3]&n[6],max(n[1]&n[4]&n[5],max(n[1]&n[4]&n[6],max(n[1]&n[5]&n[6],max(n[2]&n[3]&n[4],max(n[2]&n[3]&n[5],max(n[2]&n[3]&n[6],max(n[2]&n[4]&n[5],max(n[2]&n[4]&n[6],max(n[2]&n[5]&n[6],max(n[3]&n[4]&n[5],max(n[3]&n[4]&n[6],max(n[3]&n[5]&n[6],n[4]&n[5]&n[6])))))))))))))))))));
        else if(b==4)cout<<max(n[1]&n[2]&n[3]&n[4],max(n[1]&n[2]&n[3]&n[5],max(n[1]&n[2]&n[3]&n[6],max(n[1]&n[2]&n[4]&n[5],max(n[1]&n[2]&n[4]&n[6],max(n[1]&n[2]&n[5]&n[6],max(n[1]&n[3]&n[4]&n[5],max(n[1]&n[3]&n[4]&n[6],max(n[1]&n[3]&n[5]&n[6],max(n[1]&n[4]&n[5]&n[6],max(n[2]&n[3]&n[4]&n[5],max(n[2]&n[3]&n[4]&n[6],max(n[2]&n[3]&n[5]&n[6],max(n[2]&n[4]&n[5]&n[6],n[3]&n[4]&n[5]&n[6]))))))))))))));
        else if(b==5)cout<<max(n[1]&n[2]&n[3]&n[4]&n[5],max(n[1]&n[2]&n[3]&n[4]&n[6],max(n[1]&n[2]&n[3]&n[5]&n[6],max(n[1]&n[2]&n[4]&n[5]&n[6],max(n[1]&n[3]&n[4]&n[5]&n[6],n[2]&n[3]&n[4]&n[5]&n[6])))));
        else cout<<(n[1]&n[2]&n[3]&n[4]&n[5]&n[6]);
    }
    else if(a==7){
        if(b==1)cout<<max(n[1],max(n[2],max(n[3],max(n[4],max(n[5],max(n[6],n[7]))))));
        else if(b==2)cout<<max(n[1]&n[2],max(n[1]&n[3],max(n[1]&n[4],max(n[2]&n[3],max(n[2]&n[4],max(n[1]&n[5],max(n[2]&n[5],max(n[3]&n[5],max(n[3]&n[4],max(n[4]&n[5],max(n[1]&n[6],max(n[2]&n[6],max(n[3]&n[6],max(n[4]&n[6],max(n[5]&n[6],max(n[1]&n[7],max(n[2]&n[7],max(n[3]&n[7],max(n[4]&n[7],max(n[5]&n[7],n[6]&n[7]))))))))))))))))))));
        else if(b==3)cout<<max(n[1]&n[2]&n[3],max(n[1]&n[2]&n[4],max(n[1]&n[2]&n[5],max(n[1]&n[2]&n[6],max(n[1]&n[2]&n[7],max(n[1]&n[3]&n[4],max(n[1]&n[3]&n[5],max(n[1]&n[3]&n[6],max(n[1]&n[3]&n[7],max(n[1]&n[4]&n[5],max(n[1]&n[4]&n[6],max(n[1]&n[4]&n[7],max(n[1]&n[5]&n[6],max(n[1]&n[5]&n[7],max(n[1]&n[6]&n[7],max(n[2]&n[3]&n[4],max(n[2]&n[3]&n[5],max(n[2]&n[3]&n[6],max(n[2]&n[3]&n[7],max(n[2]&n[4]&n[5],max(n[2]&n[4]&n[6],max(n[2]&n[4]&n[7],max(n[2]&n[5]&n[6],max(n[2]&n[5]&n[7],max(n[2]&n[6]&n[7],max(n[3]&n[4]&n[5],max(n[3]&n[4]&n[6],max(n[3]&n[4]&n[7],max(n[3]&n[5]&n[6],max(n[3]&n[5]&n[7],max(n[3]&n[6]&n[7],max(n[4]&n[5]&n[6],max(n[4]&n[5]&n[7],max(n[4]&n[6]&n[7],n[5]&n[6]&n[7]))))))))))))))))))))))))))))))))));
        else if(b==4)cout<<max(n[1]&n[2]&n[3]&n[4],max(n[1]&n[2]&n[3]&n[5],max(n[1]&n[2]&n[3]&n[6],max(n[1]&n[2]&n[3]&n[7],max(n[1]&n[2]&n[4]&n[5],max(n[1]&n[2]&n[4]&n[6],max(n[1]&n[2]&n[4]&n[7],max(n[1]&n[2]&n[5]&n[6],max(n[1]&n[2]&n[5]&n[7],max(n[1]&n[2]&n[6]&n[7],max(n[1]&n[3]&n[4]&n[5],max(n[1]&n[3]&n[4]&n[6],max(n[1]&n[3]&n[4]&n[7],max(n[1]&n[3]&n[5]&n[6],max(n[1]&n[3]&n[5]&n[7],max(n[1]&n[3]&n[6]&n[7],max(n[1]&n[4]&n[5]&n[6],max(n[1]&n[4]&n[5]&n[7],max(n[1]&n[4]&n[6]&n[7],max(n[1]&n[5]&n[6]&n[7],max(n[2]&n[3]&n[4]&n[5],max(n[2]&n[3]&n[4]&n[6],max(n[2]&n[3]&n[4]&n[7],max(n[2]&n[3]&n[5]&n[6],max(n[2]&n[3]&n[5]&n[7],max(n[2]&n[3]&n[6]&n[7],max(n[2]&n[4]&n[5]&n[6],max(n[2]&n[4]&n[5]&n[7],max(n[2]&n[4]&n[6]&n[7],max(n[2]&n[5]&n[6]&n[7],max(n[3]&n[4]&n[5]&n[6],max(n[3]&n[4]&n[5]&n[7],max(n[3]&n[4]&n[6]&n[7],max(n[3]&n[5]&n[6]&n[7],n[4]&n[5]&n[6]&n[7]))))))))))))))))))))))))))))))))));
        else if(b==5)cout<<max(n[1]&n[2]&n[3]&n[4]&n[5],max(n[1]&n[2]&n[3]&n[4]&n[6],max(n[1]&n[2]&n[3]&n[4]&n[7],max(n[1]&n[2]&n[3]&n[5]&n[6],max(n[1]&n[2]&n[3]&n[5]&n[7],max(n[1]&n[2]&n[3]&n[6]&n[7],max(n[1]&n[2]&n[4]&n[5]&n[6],max(n[1]&n[2]&n[4]&n[5]&n[7],max(n[1]&n[2]&n[4]&n[6]&n[7],max(n[1]&n[2]&n[5]&n[6]&n[7],max(n[1]&n[3]&n[4]&n[5]&n[6],max(n[1]&n[3]&n[4]&n[5]&n[7],max(n[1]&n[3]&n[5]&n[6]&n[7],max(n[1]&n[4]&n[5]&n[6]&n[7],max(n[2]&n[3]&n[4]&n[5]&n[6],max(n[2]&n[3]&n[4]&n[5]&n[7],max(n[2]&n[3]&n[4]&n[6]&n[7],max(n[2]&n[3]&n[5]&n[6]&n[7],max(n[2]&n[4]&n[5]&n[6]&n[7],n[3]&n[4]&n[5]&n[6]&n[7])))))))))))))))))));
        else if(b==6)cout<<max(n[1]&n[2]&n[3]&n[4]&n[5]&n[6],max(n[1]&n[2]&n[3]&n[4]&n[5]&n[7],max(n[1]&n[2]&n[3]&n[4]&n[6]&n[7],max(n[1]&n[2]&n[3]&n[5]&n[6]&n[7],max(n[1]&n[2]&n[4]&n[5]&n[6]&n[7],max(n[1]&n[3]&n[4]&n[5]&n[6]&n[7],n[2]&n[3]&n[4]&n[5]&n[6]&n[7]))))));
        else cout<<(n[1]&n[2]&n[3]&n[4]&n[5]&n[6]&n[7]);
    }
    else cout<<511;
    return 0;
}
