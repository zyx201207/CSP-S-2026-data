#include<bits/stdc++.h>
using namespace std;
string  c_1,c_2,d_1,d_2;
bool f,ff,fff,ffff;
int main(){
 freopen("subway.in","r",stdin);
 freopen("subway.out","w",stdout);
 cin>>c_1>>c_2>>d_1>>d_2;
 if(c_1==d_1)f=1;
 if(f==1&&d_1[0]==c_1[0]&&d_1[1]==c_1[1])ff=1;
 int cc=c_2[2]-'A';
 int dd=d_2[2]-'A';
 if(cc==5)cc--;
 if(dd==5)dd--;
 if(ff==1&&cc<3&&dd<3)fff=1;
 if(ff==1&&cc>2&&dd>2)fff=1;
 int cc_1=cc++;
 int cc_2=cc--;
 int dd_1=dd++;
 int dd_2=dd--;
 if(fff==1&&(cc==dd_1||cc==dd_2||dd==cc_1||dd==cc_2))ffff=1;
 cout<<f<<ff<<fff<<ffff;
 

 return 0;
}
