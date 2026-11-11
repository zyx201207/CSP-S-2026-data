#include <iostream>

using namespace std;

string s;

bool fun01(string x){
    for(int i = 0 ; i<x.size(); i++){
        if(x[i]!=x[x.size()-i-1])
            return false;
    }
    return true;
}


int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    int a;
    char c;
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a>>c;
        for(int j = 1; j<=a; j++)
            s+=c;
    }
    int num = s.size();
    if(fun01(s)){
        cout<<0<<endl;
        return 0;
    }

    if(num%2 == 1){
        int mid = num/2;
        int cnt = 0;
        for(int i = 0; i<mid; i++){
            if(s[i]!=s[s.size()-i-1])
                cnt++;
        }
        cout<<cnt<<endl;
        return 0;
    }
    else{
        int mid = num/2;
        int cnt = 0;
        for(int i = 0; i<mid; i++){
            if(s[i]!=s[s.size()-i-1])
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
