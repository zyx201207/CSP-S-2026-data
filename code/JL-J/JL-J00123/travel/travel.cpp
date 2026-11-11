#include<cstdio>
using namespace std;
const int N=15;
char ch1[N],ch2[N],ch3[N],ch4[N];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",ch1,ch2,ch3,ch4);
    if(ch1[0]==ch3[0]&&ch1[1]==ch3[1])
    {
        printf("1");
        if(ch2[0]==ch4[0]&&ch2[1]==ch4[1])
        {
            printf("1");
            if((ch2[2]>'C'&&ch4[2]>'C')||(ch2[2]<='C'&&ch4[2]<='C'))
            {
                printf("1");
                if((ch2[2]-ch4[2]==1||ch4[2]-ch2[2]==1)&&(!((ch2[2]=='C'&&ch4[2]=='D')||(ch2[2]=='D'&&ch4[2]=='C'))))
                    printf("1");
                else printf("0");
            }
            else printf("00");
        }
        else printf("000");
    }
    else printf("0000");
}
