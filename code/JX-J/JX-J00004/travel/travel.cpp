#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>c2;
    if(c1==c2){
		cout<<"1";
    }else{
		cout<<"0000";
		return 0;
    }
    char o1=s2[0]=s2[1];
    char o2=s1[0]=s1[1];
    if(o1==o2){
		cout<<"1";
    }else{
    cout<<"000";
		}
    int p1=s1[2]-'A'+1;
    int p2=s2[2]-'A'+1;
    if((p1<=3&&p2<=3)||(p1>=4&&p2>=4)){
		cout<<"1";
    }else{
    cout<<"0";
    }
    if(abs(p1-p2)==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
    return 0;
}

