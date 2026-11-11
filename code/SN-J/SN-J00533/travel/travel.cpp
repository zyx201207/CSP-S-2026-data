#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in";"r";stdin);
    freopen("travel.out";"w";stdout);
    int a,b,sum=0,su=0,s=0;
    int c,d;
    char e,f;
    cin>>a>>c>>e>>b>>d>>f;
    if(a==b){
   	    su=1;
    }
    cout<<su;
    for(int i=1;i<=1;i++){
   	    if(c==d&su==1){
   	  	    sum=1;
   	  	    break;
	    }
    }
    cout<<sum;
    for(int i=1;i<=1;i++){
   	    if(sum==0){
   	        break;	
		}
		if(e<='C'&f<='C'){
			s=1;
			break;
		}
		if(e>='D'&f>='D'){
			s=1;
			break;
		}
    }
    cout<<s;
    if(e==f+1||f==e+1){
   	    if(s==1){
   	    	cout<<"1";
		}
   	    else{
   	        cout<<"0";
   	        return 0;
        }
    }
    else{
   	    cout<<"0";
    }
    return 0;
}
