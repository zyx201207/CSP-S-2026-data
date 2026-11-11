#include"iostream"
#include"string"
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;

    // 两张车票对应的座位是否在同一节车厢
    if(c1==c2)
        cout<<"1";
    else{
        cout<<"0000";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }

    // 两张车票对应的座位是否在同一节车厢的同一排
    if(s1[0]==s2[0]&&s1[1]==s2[1])
        cout<<"1";
    else{
        cout<<"000";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }

    // 两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧
    if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')||(s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E'))
        cout<<"1";
    else{
        cout<<"00";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }

    // 两张车票对应的座位是否相邻
    if(s1[2]+1==s2[2]||s1[2]==s2[2]+1)
        cout<<"1";
    else{
        cout<<"0";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
