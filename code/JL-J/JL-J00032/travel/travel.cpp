#include <bits/stdc++.h>
using namespace std;
char x[5] {'A','B','C','D','F'};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >>a >> b >>c >> d;
    if(a[1]!='1'&&!(a[0]=='1'&&a[1]=='6'))
    {
        cout <<'1';
    }
    else
    {
        cout<<'0';
    }
    if(b[0]==d[0]&&b[1]==b[1])
    {
        cout<<'1';
    }
    else{
        cout<<'0';
    }
    if(((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))||((b[2]=='C'||b[2]=='A'||b[2]=='B')&&(d[2]=='C'||d[2]=='A'||d[2]=='B')))
    {
		cout  <<'1';
	}
	else
	{
		cout <<'0';
	}
    int sum = 0;
    for(int i = 0;i < 5;i++){
        if(((b[2]==x[i]&&(d[2]==x[i+1]||d[2]==x[i-1])))){
            if((b[2]=='C'&&d[2]!='D')||(b[2]!='D'&&d[2]=='C'))
            {
                sum=1;
                break;
            }
        }
    }
    if(sum==1){
        cout <<'1';
    }
    else{
        cout << '0';
    }
}
