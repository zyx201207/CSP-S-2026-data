#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int r1,r2,x1,x2;
    char r,x;
    int rr,xx;
    cin>>r1>>r2>>r>>x1>>x2>>x;
    
    rr=r-'A'+1;
    xx=x-'A'+1;
    cout<<(r1==x1);
    bool c=((r1==x1)&&(r2==x2));
    cout<<c;
    
    bool d=(c&&((rr<=3&&xx<=3)||(rr>=4&&xx>=4)));
    cout<<d;
    cout<<(d&&(abs(xx-rr)==1)||(xx==4&&rr==6)||(xx==6)&&rr==4);
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}