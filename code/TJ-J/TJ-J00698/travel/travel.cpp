#include<bits/stdc++.h>
using namespace std;
int c1,s1;
char c2[10],s2[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%s%d%s",&c1,c2,&s1,s2);
	int l1=c2[2]-'A';
	int l2=s2[2]-'A';
	if(c1==s1){
		cout<<"1";
		if(c2[0]==s2[0]&&c2[1]==s2[1]){
			cout<<"1";
			if((l1<=2&&l2<=2)||(l1>=3&&l2>=3)){
				cout<<"1";
				if((l1-l2==1||l1-l2==-1)){
					cout<<"1";
				}else{
					cout<<"0";
				}
				
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
