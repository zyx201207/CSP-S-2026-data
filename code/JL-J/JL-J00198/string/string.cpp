#include<bits/stdc++.h>
using namespace std;
struct S{
    int a;
    string c;
}S[200005];
int main (){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n, o, c;
    string a[1000000000];
    cin>>n;
    for(int i=1;i<n+1;i++){
        cin>>S[i].a>>S[i].c;
    }
    for(int d = 0;d < S[n+1].a;d++){
        for(int z = 0;z <= S[d].a;z++){
            a[d] = S[d].c;
        }
    }
    for(int j = n-1;j<=0;j--){
        if (a[j]==a[o]){
            o++;
            continue;
        }else{
            c++;
        }
    }
    if(o==n/2){
        cout<<0;
    }else{
        cout<<c;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
