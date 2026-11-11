#include<bits/stdc++.h>
using namespace std;
int read(){
    int ret=0,sgn=0,ch=getchar();
    while(ch>'9'||ch<'0'){
        sgn |= ch=='-',ch=getchar();
    }
      while(ch<='9'&&ch>='0'){
        ret=ret*10+ch-'0',ch=getchar();
    }
    return sgn ? -ret:ret;
}
bool ans1,ans2,ans3,ans4; 
char c1[4],s1[4],c2[4],s2[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //ios::sync_with_stdin_(false);
    cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
    //cout<<s1[1];
    ans1=(c1[0]==c2[0]&&c1[1]==c2[1]);
    ans2=(ans1&&s1[0]==s2[0]&&s1[1]==s2[1]);
    ans3=(ans2&&(s2[2]<='C'&&s1[2]<='C')||(s1[2]>'C'&&s2[2]>'C'));
    ans4=(ans3&&(abs(s2[2]-s1[2])==1));
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
