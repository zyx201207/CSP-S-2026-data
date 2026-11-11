#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005];
int main(){
    freopen("string.in","r","stdin");
    freopen("string.out","w","stdout");
    int n;
    cin >> n;
    string m;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >>m;
    }
    for(int i=1;i<=n;i++){
    for(int j=n;j>=1;j++){
        if(a[i]==b[j]){
            break;}
            else
            {
                cnt++;
            }
            }
            }
    cout << cnt;
    return 0;
}
