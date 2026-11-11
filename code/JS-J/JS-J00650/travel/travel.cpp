#include<bits/stdc++.h>
using namespace std;

inline long long readint(){
    long long a=0;
    int c;
    bool f=0;
    c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-')f=1;
        c=getchar_unlocked();
    }
    while(c<='9'&&c>='0'&&c!=EOF){
        a=a*10+c-48;
        c=getchar_unlocked();
    }
    return f?-a:a;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int a1,b1;
    string a2,b2;
    cin>>a1>>a2>>b1>>b2;
    array<int,4>ans{0,0,0,0};
    if(a1==b1){
        ans[0]=1;
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
            ans[1]=1;
            if(a2[2]<='C'&&b2[2]<='C'){
                ans[2]=1;
                if(a2[2]+1==b2[2]||a2[2]-1==b2[2])
                    ans[3]=1;
            }else if(a2[2]>='D'&&b2[2]>='D')
                ans[3]=ans[2]=1;
        }
    }
    for(int i=0;i<=3;i++)
        cout<<ans[i];
    return 0;
}