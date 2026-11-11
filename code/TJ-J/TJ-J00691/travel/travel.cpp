#include<bits/stdc++.h>
using namespace std;
char c[5];
char s[5];
int main(){
	freopen("travelin","r",stdin);
	freopen("travelout","w",stdout);
	for(int i=1;i<=5;i++){
        cin>>c[i];
	}
	for(int i=1;i<=5;i++){
        cin>>s[i];
	}
	if(c[1]==s[1] && c[2]==s[2]){
        cout<<1;
        if(c[3]==s[3] && c[4]==s[4]){
            cout<<1;
            if(c[5]+s[5]-'A'+1<='E' && c[5]+s[5]-'A'+1>='C'){
                cout<<1;
               	if(int(c[5]-s[5])==1 || int(s[5]-c[5])==1){
        			cout<<1;
				}
				else{
   				    cout<<0;
				}
            }
            else if(c[5]+s[5]-'A'+1=='J'){
                cout<<1<<1;
                return 0;
            }
            else{
                cout<<0<<0;
            }
    	}
        else{
            cout<<0<<0<<0;
        }
	}
	else{
        cout<<0<<0<<0<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
