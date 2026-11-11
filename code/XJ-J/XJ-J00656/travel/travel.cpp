#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str,str1,str2,str3,a,b;
	cin>>str>>str1>>str2>>str3;
	int n,m,x,y,k,l;
	n=str1[2]-'A';
	m=str3[2]-'A';
	x=str1[0]-'0';
	y=str1[1]-'0';
	k=str3[0]-'0';
	l=str3[1]-'0';
	if(str!="01"||str!="16"||str2!="01"||str2!="16"){//判断是否为二等座
		if(str[0]==str2[0]&&str[1]==str[1]){//是否在同一车厢
		cout<<'1';
			if(x==k&&y==l){//判断是否在同一排
				cout<<'1';
				if(m!=n){
					if(((n==0||n==1||n==2)&&(m==0||m==1||m==2))||((n==3||n==4)&&(m==3||m==4))){//判断是否在同一侧
						cout<<'1';
						if((str1[2]=='A'&&str3[2]=='B')||(str1[2]=='B'&&str3[2]=='C')||(str1[2]=='D'&&str3[2]=='F')){//判断是否相邻
							cout<<'1';
							return 0;
						}else{
							cout<<'0';
							return 0;
						}				
					}else{
						cout<<"00";	
						return 0;			
					}
				}
			}else{
				cout<<"000";
				return 0;
			}
		}else{
			cout<<"0000";
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