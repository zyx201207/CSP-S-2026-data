#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a;
    char b;
    cin>>n;
    string s;
    vector<int>arr(n);
    while(n){
        n--;
        int temp = 0;
        temp++;
        cin>>a>>b;
        arr[temp] = a;
        for(int i = 0;i<a;i++){
            s+=b;
        }
    }
    if(n == 1)cout<<a;
    if(n == 2)cout<<min(arr[1],arr[0]);

}
