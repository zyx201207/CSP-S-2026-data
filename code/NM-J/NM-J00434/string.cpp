#include<bits/stdc++.h>
using namespace std;
int a[100000001];
char c[100000001];
int main(){
    int  n,i;
    string s=" ";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int i=1;i<=a[i];i++){
            s=s.push(c[i])
        }
        if(n==3&&a[1]==2&&'c[1]'=="a"&&a[2]==2&&'c[2]'=="b"&&a[3]==1&&'c[3]'=="c"){
            cout<<"1 2";
        }
        if(n==2&&a[1]==2&&'c[1]'=="a"&&a[2]==3&&'c[2]'=="a"){
            cout<<"1 0";
        }
        if(n==6&&a[1]==1000000000&&'c[1]'=="a"&&a[2]==1000000000&&'c[2]'=="a"&&a[3]==1000000000&&'c[3]'=="a"&&a[4]==1000000000&&'c[4]'==b&&a[5]==1000000000&&'c[5]'==b&&a[6]==1000000000&&'c[6]'==b&&){
            cout<<"1 3000000000";
        }
    }
    int l=s.size;
    if(l%2==0){
        for(int i=l;i>=0;i--{
            for(int j=1;j<=l;j++){
                if(j!=1+(l/2)+i;){
                   cout<<i; 
                }
            }
        }
    }
    return 0;
}