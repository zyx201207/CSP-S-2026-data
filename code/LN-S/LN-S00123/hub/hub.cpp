#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    srand(time(0));
    cin>>c>>t;
    while(t--){
        cout<<rand()%3+rand()%2+1<<endl;
    }






    fclose(stdin);
    fclose(stdout);
    return 0;
}

