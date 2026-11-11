#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
  //  ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c,s,cc,ss;
    cin>>c>>s>>cc>>ss;
    if(c==cc)cout<<"1";
    else{
        cout<<"0000"<<endl;
        fclose(stdin);
    fclose(stdout);
        return 0;
    }
    if(s[0]==ss[0]&&s[1]==ss[1])cout<<"1";
    else{
        cout<<"000"<<endl;
        fclose(stdin);
    fclose(stdout);
        return 0;
    }
    int a,aa;
    if(s[2]=='D'||s[2]=='E') a=1;
    else a=0;
    if(ss[2]=='D'||ss[2]=='E') aa=1;
    else aa=0;
    if(a==aa)cout<<'1';
    else{
        cout<<"00"<<endl;
        fclose(stdin);
    fclose(stdout);
        return 0;
    }
    if(a==1)cout<<"1"<<endl;
    else if(abs(s[2]-ss[2])==1)cout<<"1"<<endl;
    else cout<<"0"<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
