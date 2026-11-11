#include <iostream>

using namespace std;

int n,m;

string s[555555];

int main()
{
    cin>>n>>m;

    if(m>3000){

        return 0;
    }

    for(int i=1,in;i<=n;i++){
        cin>>in;

        for(int j=1;j<=i;j++){

            s[j][i]=in;

            bool flag=true;

            for(int k=1;k<=i;k++){

                s[j][k]*=flag;

                if(s[j][k]==in)flag=false;

            }
        }
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                s[s[i][j]][0]++;
    }
    for(int i=1;i<=n;i++)cout<<(int)s[i][0]<<' ';
    return 0;
}
