#include<bits/stdc++.h>
using namespace std;
int n,num,leng;
char str;
vector<char> stri;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        cin>>str;
        leng+=num;
        for(int j=0;j<num;j++) stri.push_back(str);
    }
    bool fl=true;
    if(leng%2==0){
        for(int i=0;i<leng/2;i++){
            if(stri[i]!=stri[leng-1-i]){
                fl = false;
            }
        }
    }
    else if(leng%2!=0){
        for(int i=0;i<leng/2;i++){
            if(stri[i]!=stri[leng-i]){
                fl = false;
            }
        }
    }
    if(fl==true or n==1){
        cout<<0;
    }
    else{
        if(n==2){
            cout<<n/2;
        }
    }
    return 0;
}
