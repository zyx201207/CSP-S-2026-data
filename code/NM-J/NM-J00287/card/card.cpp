#include <iostream>

using namespace std;
string a[5000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,s=0;
    cin>>n>>m>>a;
    for(int i;i<=m;i++){
        for(int i;i<=a.size();i++){
            if(a[1]==a[i]){
                s++;

            }
        }
        if(s%2==0){
            cout<<s;
        }
    }


    return 0;
}
