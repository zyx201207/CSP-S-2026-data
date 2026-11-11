#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string ans;
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
        ans+="1";
        string a,b;
        a=a2[0]+a2[1];
        b=b2[0]+b2[1];
        if(a==b){
            ans+="1";
            string num1,num2;
            num1=a2[2];
            num2=b2[2];
            if(num1=="A"||num1=="B"||num1=="C"){
                num1=1;
            }
            else{
                num1='0';
            }
            if(num2=="A"||num2=="B"||num2=="C"){
                num2=1;
            }
            else{
                num2='0';
            }
            if(num1==num2){
                ans+="1";
                if(a2[2]=='A'&&b2[2]=='B'){
                    cout<<1;
                }
                else if(a2[2]=='B'&&b2[2]=='A'){
                    cout<<1;
                }
                else if(a2[2]=='B'&&b2[2]=='C'){
                    cout<<1;
                }
                else if(a2[2]=='C'&&b2[2]=='B'){
                    cout<<1;
                }
                else if(a2[2]=='D'&&b2[2]=='F'){
                    cout<<1;
                }
                else if(a2[2]=='F'&&b2[2]=='D'){
                    cout<<1;
                }
                else{
                    ans+="0";
                }

            }

            else{
                ans+="00";
            }
        }
        else{
            ans+="000";
        }

	}
	else{
        ans+="0000";
	}
	
	if(ans.size()==3){
		ans+="0";
	}
	else if(ans.size()==2){
		ans+="00";
	}
	else if(ans.size()==1){
		ans+="000";
	}
	
	cout<<ans;
	
	return 0;
}
