#include<bits/stdc++.h>
using namespace std;
int main(){

   // cout<<"freopen file name"<<endl;

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    bool ans1 = 0,ans2 = 0,ans3 = 0,ans4 = 0;

   
    

    string a1,a2,b1,b2;

    cin>>a1>>a2>>b1>>b2;

    int n = a2[0]*10+a2[1];
    int m = b2[0]*10+b2[1];

    ans1 = a1==b1;
    if(n==m&&ans1) ans2 = 1;

    char nn,mm;
    nn = a2[2];
    mm = b2[2];
	
    if('D'-nn>0&&'D'-mm>0&&ans2) ans3 = 1;
    else if('D'-nn<=0&&'D'-mm<=0&&ans2) ans3 = 1;
    
    int x = abs(int(a2[2]-b2[2]));

    if(x==1&&ans3) ans4 =1;

	cout<<ans1<<ans2<<ans3<<ans4;
	
    return 0;
}