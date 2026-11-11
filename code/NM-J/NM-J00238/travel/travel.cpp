#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("tavel.in","r",stdin)
    freclose("tavel.out","w",stdout)
    cout<<fixed<<setprecision(2)<<3.141592;
    fclose(stdin);
    fclose(stdout)
    struct c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1.size(2)==s2.size(2)){
        	cout<<"1";
        	if(s1.size(3)-s2.size(3)==1){
                cout<<"1";
                if(s1.size(3)=="A"&&s2.size(3)=="B"||s1.size(3)=="B"&&s2.size(3)=="C"||s1.size(3)=="D"&&s2.size(3)=="E"){
                    cout<<"1";
            }
		}
    }
    if(c1!=c2){
        cout<<"0";
        if(s1.size(2)!=s2.size(2)){
        	cout<<"0";
        	if(s1.size(3)-s2.size(3)!=1)){
        		cout<<"0";
        		if(s1.size(3)=="A"&&s2.size(3)!="B"||s1.size(3)=="D"&&s2.size(3)!="E"){
                    cout<<"0";
        		}
			}
		}
    }
    return 0;
}
