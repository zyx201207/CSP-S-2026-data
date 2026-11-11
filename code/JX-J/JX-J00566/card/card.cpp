#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int num[300005];
void calc(int f){
    bool u[300005];
    int last = f;
    for(int i = f;i<n;i++){
        if(u[i] == true){
            for(int j = i-1;j>=last;j--){
                u[j] = false;
            }
            last = i;
        }
        u[i] = true;
    }
    for(int i = 1;i<=m;i++){
        if(u[i]) num[i]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i =0;i<n;i++){
        cin>>a[i];
    }

    for(int i = 0;i<n;i++){
        calc(i);
    }

    for(int i = 1;i<=m;i++){
        cout<<num[i]<<" ";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
