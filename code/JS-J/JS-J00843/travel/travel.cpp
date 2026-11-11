#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("trevel.out","w",stdout);

    string num1,seat1,num2,seat2,s1,s2;
    char e1,e2;
    cin>>num1>>seat1>>num2>>seat2;
    if (num1!=num2){
        cout<<"0000";
        return 0;
        fclose(stdin);
        fclose(stdout);
    }
    s1=seat1[0]+seat1[1];e1=seat1[2];
    if (seat1[2]<='9' and seat1[2]>='0'){
        s1+=seat1[2];e1=seat1[3];
    }
    s2=seat2[0]+seat2[1];e2=seat2[2];
    if (seat2[2]<='9' and seat2[2]>='0'){
        s2+=seat2[2];e2=seat2[3];
    }
    if (s1!=s2){
        cout<<"1000";
        return 0;
        fclose(stdin);
        fclose(stdout);
    }
    int aa=0;
    if ((int(e1)<=67 and int(e2)<=67)or(int(e1)>=68 and int(e2)>=68)){
        aa=1;
    }
    if (aa==0){
        cout<<"1100";
        return 0;
        fclose(stdin);
        fclose(stdout);
    }
    int m=int(e1)-int(e2);
    if (m!=1 and m!=-1){
        cout<<"1110";
        return 0;
        fclose(stdin);
        fclose(stdout);
    }
    else{
        cout<<"1111";
    }

    return 0;
    fclose(stdin);
    fclose(stdout);
}
