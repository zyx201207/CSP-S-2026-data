#include<bits/stdc++.h>
using namespace std;
long long n,num=0;
string S;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int a[n];
    char c[n];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            S.push_back(c[i]);
        }
    }

    int i=0,j=S.size()-1;
    while(i<=j){
        if(S[i]!=S[j])num++;
        i++;
        j--;
    }
    cout<<num;
    return 0;
}
