#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long sum = 0,sum2 = 0;
    int n,cnt = 1;
    cin>>n;
    int x;
    char c,a[3000005];
    if(n == 1){
        cin>>x;
        cout<<0;
        return 0;
    }else{
        for(int i = 1;i <= n;i++){
            cin>>x;
            cin>>c;
            for(int i = 1;i <= x;i++){
                a[cnt++] = c;
            }
            sum += x;
        }
        for(int i = 1;i <= (sum / 2);i++){
            if(a[i] != a[sum - i + 1]) sum2++;
        }
        cout<<(sum2?sum2:0);
    }
    return 0;
}
