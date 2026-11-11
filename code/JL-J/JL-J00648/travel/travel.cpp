#include<bits/stdc++.h>
using namespace std;
int a[20];
char s[3],s2[4],s3[3],s4[4];

int main()
{
    for(int i=1;i<=2;i++)cin>>s[i];
    for(int i=1;i<=3;i++)cin>>s2[i];
  for(int i=1;i<=2;i++)cin>>s3[i];
    for(int i=1;i<=3;i++)cin>>s4[i];

    if(s[1]-'0'==0&&s[2]-'0'==1 || s[1]-'0'==1&&s[2]-'0'==6 ||s3[1]-'0'==0&&s3[2]-'0'==1 ||s3[1]-'0'==1&&s3[2]-'0'==6)
        cout<<"0000"<<endl;
    else{
        if(s[2]-'0'==s3[2]-'0'){
        a[1]=1;
         if(s2[1]-'0'==s4[1]-'0'&&s2[2]-'0'==s4[2]-'0')a[2]=1;else a[2]=0;
         if(s2[3]-'0'=='C'&&s4[3]-'0'=='D' ||s2[3]-'0'=='D'&&s4[3]-'0'=='C'){
            a[3]=0;
            a[4]=0;
         }

        else{
              a[3]=1;
         if(s2[3]-'0'=='A'&&s4[3]-'0'=='C'|| s2[3]-'0'=='C'&&s4[3]-'0'=='A' )a[4]=0;
         else a[4]=1;
          }
    }



    for(int i=1;i<=4;i++)
            cout<<a[i];
    cout<<endl;


    }



freopen("travel.in","r","in");
  freopen("travel.out","w","out");
    return 0;
}
