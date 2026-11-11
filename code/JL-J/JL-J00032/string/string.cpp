#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >>n;
    string s;
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        char a;
        cin >> a;
        for(int i = 1;i <= x;i++)
        {
            s+=a;
        }
    }
    int sum=0;
    int cnt = s.length();
    for(int i = 0;i < cnt;i++)
    {
        if(
           s[i]!=s[cnt-1])
        {
            s[cnt-1]=s[i];
            sum++;
        }
        cnt--;
    }
    cout<<sum;
}
