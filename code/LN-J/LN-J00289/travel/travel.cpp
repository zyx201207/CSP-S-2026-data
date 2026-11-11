#include <bits/stdc++.h>
using namespace std;
int ans[4];
void print(){
    for(int i=0;i<4;i++)cout<<ans[i];
    cout<<endl;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string s1,s2;
    cin>>a>>s1>>b>>s2;
    if(a!=b){
        print();
        return 0;
    }
    ans[0]=1;
    if(!(s1[0]==s2[0]&&s1[1]==s2[1])){
        print();
        return 0;
    }
    ans[1]=1;
    int c1=(s1[2]-'A'),c2=(s2[2]-'A');
    cout<<c1<<c2<<endl;
    if(!((c1<=2&&c2<=2)||(c1>=3&&c2>=3))){
        print();
        return 0;
    }
    ans[2]=1;
    if(c1<=2){
        if(abs(c1-c2)!=1){
            print();
            return 0;
        }
    }
    ans[3]=1;
    print();
    return 0;
}
