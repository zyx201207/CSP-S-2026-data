#include <iostream>
#include<string>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    cin>>a;
    int b;
    char c;
    string d;
    for(int i=0;i<a;i++){
        cin>>b;
        cin>>c;
        for(int j=0;j<b;j++){
            d+=c;
        }
    }
    int e=d.length();
    int f=0;
    for(int i=0;i<e;i++){
        if(d[i]!=d[e-i]){
            d[e-i]=d[i];
            f++;
        }
    }
    cout<<f-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
