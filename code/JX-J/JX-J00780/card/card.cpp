#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,sum=0;
    queue<char> q;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char x;
        cin>>x;
        q.push(x);
    }
    while(n--){
        string w+=q.front();
        q.pop();

    }
    cout<<sum;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
