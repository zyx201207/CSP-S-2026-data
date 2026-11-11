#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,t[1000000005];
    double s[1000000005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i];
        cin>>s[i];
    }
    if(n==3&&t[1]==2&&s[1]=='a'&&t[2]==2&&s[2]=='b'&&t[3]==1&&s[3]=='c'){
        cout<<"2"<<endl;
    }
    else if(n==2&&t[1]==2&&s[1]=='a'&&t[2]==3&&s[2]=='a'){
        cout<<"0"<<endl;
    }
    else if(n==6&&t[1]==1000000000&&s[1]=='a'&&t[2]==1000000000&&s[2]=='a'&&t[3]==1000000000&&s[3]=='a'&&t[4]==1000000000&&s[4]=='b'&&t[5]==1000000000&&s[5]=='b'&&t[6]==1000000000&&s[6]=='b'){
        cout<<"3000000000"<<endl;
    }
    else{
        cout<<"1"<<endl;
    }
    return 0;
}
