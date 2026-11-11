#include<iostream>
using namespace std;

string c1,s1,c2,s2;
bool flag;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    flag = c1==c2;
    cout<<flag;
    flag = flag&&s1[0]==s2[0]&&s1[1]==s2[1];
    cout<<flag;
    flag = flag&&!((s1[2]<'D')^(s2[2]<'D'));
    cout<<flag;
    flag = flag&&(s1[2]-s2[2]==1||s1[2]-s2[2]==-1);
    cout<<flag;
    return 0;
}
