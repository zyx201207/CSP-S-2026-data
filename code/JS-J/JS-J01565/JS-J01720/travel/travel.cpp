#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,ans1=0,ans2=0,ans3=0,ans4=0;
    char c,d;
    string c1,s1,c2,s2;
    s1=a+c;
    s2=b+d;
    cin>>c1>>s1>>c2>>s2>>a>>b>>c>>d;
    if(c1==c2){
        ans1+=1;
    }
    else
        ans1+=0;
    if(c1==c2||a==b)
         ans2+=1;
    else
        ans2+=0;
    if(c1==c2||a==b||abs(c)!=68||abs(d)!=69){
          ans3+=1;
          }
        else
        ans3+=1;
    if(c1==c2){
	if(a==b){
		if(abs(c)!=68||abs(d)!=69||abs(d-c)==1){
		ans4+=1
	} 
}
}
    else
        ans4+=0;
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
