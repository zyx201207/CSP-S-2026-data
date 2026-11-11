#include <bits/stdc++.h>
using namespace std;
string a,b,f1,f2;//a,b表示数字；f1,f2表示字符 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){//是否同一车厢 
		cout <<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=1;i<=s1.size();i++){
		if(s1[1]>='0'&&s1[i]<='9'){
			a=a+s1[i];
		}
		else{
			f1=f1+s1[i];
		}
	}
	for(int i=1;i<=s2.size();i++){
		if(s2[1]>='0'&&s2[i]<='9'){
			b=b+s2[i];
		}
		else{
			f2=f2+s2[i];
		}
	}
	//那么，现在a和b就是排数，f1和f2就是座位号 
	if(a==b){//是否同一排 
		cout <<1;
}
	else{
		cout <<0;
	}
	if(f1>='D' && f2>='D'){//是否不隔过道 
		int m=1;
		cout <<1;
	}
	else if((f1>='A'&&f1<='C') && (f2>='A'&&f2<='C')){ 
		int m=1;
		cout <<1;
	}
	else{
		int m=0;
		cout << 0;
		}
	if((f1-f2==1||f2-f1==1)&&m==1){//是否相邻 
		cout << 1;
	}
	else if(f1=='D'||f2=='D'){
		if(f1=='D'&&f2=='F')cout <<1;
		else if(f1=='F'&&f2=='D')cout <<1;
		else{
			cout<<0;
			break;
		}
	}
	else{
		cout <<0
	} 
	
	return 0;
}
