#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string st[MAX];
    int n,a,s = 0,num = 0,sum = 0;
    char c;
    cin>>n;
    for(int i = 1; i<= n;i++){
        cin>>a>>c;
        s += a;
        for(int j = 0;j < a;j++){
            st[sum] = c;
            sum++;
        }
    }
    string st1[MAX];
    sum = 0;
    for(int i = s - 1;i >= 0;i--){
        st1[sum] = st[i];
        sum++;
    }
    sum = 0;
    for(int i = 0;i < s;i++){
        if(st1[i] !=st[i]){
            sum = 1;
            break;
        }
    }
    if(sum == 0){
        cout<<num;
        return 0;
    }
    sum = 0;
    for(int i = s - 1;i >= 0;i--){
        if(st[sum] != st[i]){
            st[i] = st[sum];
            num++;
        }
        sum++;
    }
    cout<<num;
    return 0;
}
