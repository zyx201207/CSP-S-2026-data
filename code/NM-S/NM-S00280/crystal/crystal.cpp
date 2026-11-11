#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int a=0,b=0,c=0,e=0,n=0,m=0,sj[105]={0};
    cin>>n,m;
    for (int i = 1; i < n; i++){
        cin>>sj[i];
        b=i;
    }
    for (int i = 1; i < m; i++){
            if(sj[b]+i==sj[i+1]){
                a++;
            }
        }
    cout<<a;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
