#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>a[i-1]&&i!=1){
            cout<<i-1<<' ';
        }
    }cout<<n<<'\n';

    return 0;
}
/*I am a juruo QAQ

           <wo shi qu awa>
       /--
    __/``
__--.,''


        __====                                ||=====||                  ||==================
    __==          ||    \\                    ||     ||                  ||
        ||         |\    \\                   ||==== ||                  ||
        ||          ||                        ||     ||                  ||
 =======++==========++========                ||=====||                  ||     \\    //
        ||          |\               =============================       ||       \\//
        ||  /        ||                          ||                      ||       //\\
        || =/        ||                          ||                      ||     //    \\
        |//          \\   //              //     ||====                  ||
       //|           ||  |/               /|     ||                      ||
      //||            \\//               //      ||                      ||
     _= ||           //\\               //==___  ||                      ||
        ||          //  ||             //      ==++=====______           ||==================
     \\ //         //   \\ //
      \V/                \V/

!?qu qu?!
woshiquwoshiquwoshiquwoshiquwoshiquwoshiquwoshiquwoshiquwoshiquwoshiquwoshiquwoshiquwoshiquwoshiquwoshiquququququququq
*/
