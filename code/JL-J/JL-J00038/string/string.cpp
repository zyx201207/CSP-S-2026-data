#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int sum=0,l_e=-1,n,num[1396000];
    char l[1396000];
    char s[1396000];
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> num[i];
        cin >> l[i];
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=num[i+1];j++){
            s[i]=l[i+1];
            l_e++;
        }
    }
    for(int i=0;i<l_e/2;i++){
        if(s[i]!=s[l_e-i]){
            sum++;
        }
    }
    cout << sum;
    return 0;
}
