#include<bits/stdc++.h>
using namespace std;
int main(){
    string c1,c2,r1,r2;

    freopen("travel.in",r,stdin);
    freopen("travel.out",w,stdout);
    cin>>c1>>r1>>c2>>r2;
    if(c1!=c2){
	cout<<"0000";
	fclose("travel.in",r,stdin);
    	fclose("travel.out",w,stdout);
	return 0;
    }
    cout<<1;
    if(r1[0]==r2[0]&&r1[1]==r2[1]&&r1[2]==r2[2]){
    	cout<<1;
    	if(r1[2]<='C'&&r2[2]<='C'){
    	    cout<<1;
    	}else{
    	    cout<<0;
    	}
    }else{
    	cout<<0<<0;
    }
    if(r1[0]==r2[0]&&r1[1]==r2[1]&&((r1[2]!='D'&&r2[2]!='C')||(r1[2]!='C'&&r2[2]!='D'))){
        if(r1[2]+1==r2[2]||r1[2]-1==r2[1]){
            cout<<1;
    	}else{
    	    cout<<0;
    	}
    }else{
    	cout<<0;
    }

    fclose("travel.in",r,stdin);
    fclose("travel.out",w,stdout);
    return 0;
}
