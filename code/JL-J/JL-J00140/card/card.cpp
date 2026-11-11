#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    vector<int>a;
    cout<<3<<1<<4<<" ";
    int sum = 0;
    for(int i = 0;i < n;i++){
        cin>>a[i]>>endl;
        sum++;
        if(a[1] == a[i]){
           a.empty();
           continue;
         }
        if(i == m){
           cout<<sum<<a[i];
           cout<<sum + a[i];
        }
    }
fclose;
return 0;
}
