#include <iostream>
using namespace std;
string s;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    getline(cin,s);
    if (s[0]==s[7]&&s[1]==s[8])
    {
        printf("1");
        if (s[3]==s[10]&&s[4]==s[11])
        {
            printf("1");
            if ((s[5]<='C'&&s[12]<='C')||(s[5]>'C'&&s[12]>'C'))
            {
                printf("1");
                if ((s[5]=='A'&&s[12]=='B')||(s[5]=='B'&&s[12]=='A')||(s[5]=='B'&&s[12]=='C')||(s[5]=='C'&&s[12]=='B')||(s[5]=='D'&&s[12]=='F')||(s[5]=='F'&&s[12]=='D'))
                    printf("1");
                else printf("0");
            }
            else printf("00");
        }

        else printf("000");
    }

    else printf("0000");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
