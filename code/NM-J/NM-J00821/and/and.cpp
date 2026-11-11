#include <iostream>

using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a;
    cin>>a;
    int b;
    cin>>b;
    int c[a];
    for(int i=0;i<a;i++){
        cin>>c[i];
    }
    int d=0;
    int f=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
                int e=0;
            if(e+1>a){
                d=c[e]&c[0];
                e=0;
            }else{
                d=c[e]&c[e]+1;
                e++;
            }
        }
        if(d>f){
            f=d;
        }
    }
    cout<<f;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
