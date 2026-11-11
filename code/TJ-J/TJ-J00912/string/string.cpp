#include <bits/stdc++.h>
using namespace std;
int a[200005],cnt;
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    bool flag = false;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    int num = n/2;
    if(num%2!=0){
        num+=1;
        flag = true;
    }
    if(flag){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i];j++){

            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
