include <iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,num=0;
    long long le=0;
    cin >> n;
    string l;
    for(int i=1;i<=n;i++){
        int m;
        cin >> m;
        char p;
        cin >> p;
        for(int j=1;j<=m;j++){
            l+=p;
        }
        le+=m;
    }
    for(int i=0;i<le/2;i++){
        if(l[i]!=l[le-i-1]){
            l[le-i-1]=l[i];
            num++;
        }
    }
    cout<<num;
    return 0;
}
