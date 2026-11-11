#include<bits/stdc++.h>
using namespace std;
int cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    long long  shu[n +5];
    char a[n+5];
    long long db = 0;
    for(int i=0;i<n;i++){
        cin>>shu[i];
        db = db + shu[i];
        cin>>a[i];
    }

    for(int i=0;i<db/2;i++){
            long long t = 0;
            long long tt = db - 1;
        while(i+1>shu[t]){
            i = i - shu[t];
            t++;
        }
         while(i+1>shu[tt]){
            i = i - shu[tt];
            tt--;
        }
        if(a[t] !=a[tt]) cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
