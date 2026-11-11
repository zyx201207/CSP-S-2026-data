#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+1;

int main(){
    
    cin.tie(nullptr);ios::sync_with_stdio(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a1=(c1==c2),a2=(s1[0]==s2[0]&&s1[1]==s2[1]&&a1),a3;
    cout<<a1<<a2;
    
    
  
        if(a2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='F'))){
        a3=1;
        
    }else{
        a3=0;
    }
    cout<<a3;
    if(a3&&abs(int(s1[2])-int(s2[2]))==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}