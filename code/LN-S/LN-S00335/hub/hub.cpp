#include <iostream>

using namespace std;

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;i++){
                srand(time(0));
                int i=rand()%n+1;
                cout<<i<<"\n";
            }


        }
    }
    return 0;
}
