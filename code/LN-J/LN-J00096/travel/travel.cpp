 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {

     freopen("travel.in","r",stdin);
     freopen("travel.out","w",stdout);

     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     string n,m,a,b; cin>>n>>m>>a>>b;

     if(n==a)
     {
        cout<<1;
        if(m[0]==b[0] && m[1]==b[1])
        {
            cout<<1;
            if((m[2]=='A' || m[2]=='B' || m[2]=='C') && (b[2]=='A' || b[2]=='B' || b[2]=='C')){
                cout<<1;
                if((m[2]=='A' && b[2]=='B') || (m[2]=='B' && b[2]=='A'))cout<<1;
                else if((m[2]=='B' && b[2]=='C') || (m[2]=='C' && b[2]=='B'))cout<<1;
                else cout<<0;
            }
            else if((m[2]=='D' || m[2]=='F') && (b[2]=='D' || b[2]=='F')){
                cout<<1;
                if(m[2]=='D' && b[2]=='F')cout<<1;
                else if(m[2]=='F' && b[2]=='D') cout<<1;
                else cout<<0;
            }
            else {
                cout<<0;
                cout<<0;
            }
        }
        else {
            cout<<0;
            cout<<0;
            cout<<0;
        }
    }
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
    }
    return 0;
 }
