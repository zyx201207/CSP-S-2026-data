#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
        printf("0000\n");
    else{
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            char k1=s1[2],k2=s2[2];
            if(k1>k2)
                swap(k1,k2);
            if((k1=='A'||k1=='B'||k1=='C')&&(k2=='A'||k2=='B'||k2=='C')){
                if(k1==k2-1)
                    printf("1111\n");
                else
                    printf("1110\n");
            }
            else if((k1=='D'||k1=='F')&&(k2=='D'||k2=='F'))
                printf("1111\n");
            else
                printf("1100\n");
        }
        else
            printf("1000\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
