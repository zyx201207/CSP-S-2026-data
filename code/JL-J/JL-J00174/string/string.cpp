
#include<iostream>
using namespace std;

int main(){freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n<=2){
        int a;
    string b;
    string str;
    int minn=0;
        for(int i=1;i<=n;i++){
            cin>>a>>b;
            minn=min(a,minn);
            for(int j=1;j<=a;j++){
                str+=b;
            }
        }
        cout<<minn;
    }
    string b;
    int a;
    char key=' ';
    string str;
        for(int i=1;i<=n;i++){
            cin>>a>>b;
            for(int j=1;j<=a;j++){
                str+=b;
            }
        }
        key=str[0];
        for(int i=0;i<str.size();i++){
            if(key!=str[i]){
                key='%';
                break;
            }
        }
        if(key!='%'){
            cout<<0;
            return 0;
        }
        else{
            cout<<n/2;
        }
    return 0;
}
