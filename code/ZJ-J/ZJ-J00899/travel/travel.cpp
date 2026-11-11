#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int a,b;
    string aa,bb;
    cin>>a>>aa>>b>>bb;
    if(a==b){
        cout<<1;
        if(aa[0]==bb[0]&&aa[1]==bb[1]){
            cout<<1;
            if((aa[2]<='C'&&bb[2]<='C')||(aa[2]>='D'&&bb[2]>='D')){
                cout<<1;
                if((abs(int(aa[2]-bb[2]))==1)||(aa[2]=='D'&&bb[2]=='F')||(aa[2]=='F'&&bb[2]=='D')) cout<<1;
                else cout<<0;
            }
            else cout<<0<<0;
        }
        else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;


    fclose(stdin);
    fclose(stdout);
    return 0;
}
