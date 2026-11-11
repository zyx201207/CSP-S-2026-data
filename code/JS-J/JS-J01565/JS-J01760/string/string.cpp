#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string str1="",str2="";
    int n;
    cin>>n;
    while(n--){
        int a;
        char c;
        cin>>a>>c;
        for(int j=0;j<a;j++){
            str1=str1+c;
            str2=c+str2;
        }
    }
    int cnt=0;
    for(int i=0;i<str1.size();i++){
        if(str1[i]!=str2[i])cnt++;
    }
    cout<<cnt/2;
    return 0;
}
