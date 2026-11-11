#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    string c1,c2;
    char a,b,c,x,y,z;
    cin>>c1>>a>>b>>c>>c2>>x>>y>>z;
    if(c1==c2) cout<<"1";
    else{
        cout<<0000;
        return 0;
    }
    if(a==x&&b==y) cout<<"1";
    else {
        cout<<000;
        return 0;
    }
    if(c=='D'&&z=='F'){
        cout<<11;
        return 0;
    }
    else if(c=='F'&&z=='D'){
        cout<<11;
        return 0;
    }
    else if(c=='A'&&z=='B'){
        cout<<11;
        return 0;
    }
    else if(c=='B'&&z=='A'){
        cout<<11;
        return 0;
    }
    else if(c=='B'&&z=='C'){
        cout<<11;
        return 0;
    }
    else if(c=='C'&&z=='B'){
        cout<<11;
        return 0;
    }
    else if(c=='A'&&z=='C'){
        cout<<10;
        return 0;
    }
    else if(c=='C'&&z=='A'){
        cout<<10;
        return 0;
    }
    else if(c=='A'&&z=='D'){
        cout<<00;
        return 0;
    }
    else if(c=='A'&&z=='F'){
        cout<<00;
        return 0;
    }
    else if(c=='D'&&z=='A'){
        cout<<00;
        return 0;
    }
    else if(c=='F'&&z=='A'){
        cout<<00;
        return 0;
    }
    else if(c=='B'&&z=='D'){
        cout<<00;
        return 0;
    }
    else if(c=='B'&&z=='F'){
        cout<<00;
        return 0;
    }
    else if(c=='D'&&z=='B'){
        cout<<00;
        return 0;
    }
    else if(c=='F'&&z=='B'){
        cout<<00;
        return 0;
    }
    else if(c=='C'&&z=='D'){
        cout<<00;
        return 0;
    }
    else if(c=='C'&&z=='F'){
        cout<<00;
        return 0;
    }
    else if(c=='D'&&z=='C'){
        cout<<00;
        return 0;
    }
    else if(c=='F'&&z=='C'){
        cout<<00;
        return 0;
    }
    return 0;
}
