#include<iostream>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    long long ans = 0;
    string S = "";
    cin >> n;
    for(int i=0;i<n;i++){
        long long a;
        char c;
        cin >> a >> c;
        for(int i=0;i<a;i++){
            S+=c;
        }
    }
    int Slong;
    if(S.length()%2!=0){
        Slong = S.length()-1;
    }else{
        Slong = S.length();
    }
    for(int i=0;i<Slong/2;i++){
        if(S[i]!=S[S.length()-i-1]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
