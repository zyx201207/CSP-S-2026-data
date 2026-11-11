#include<bits/stdc++.h>
using namespace std;
char l1,l2;
string c1,s1,c2,s2;
bool kkk(){
	if(l1=='A'){
		if(l2=='B'){
			return true;
		}
		else{
			return false;
		}
	}
	else if(l1=='B'){
		if(l2=='A'||l2=='C'){
			return true;
		}
		else{
			return false;
		}
	}
	else if(l1=='C'){
		if(l2=='B'){
			return true;
		}
		else{
			return false;
		}
	}
	else if(l1=='D'){
		if(l2=='E'){
			return true;
		}
		else{
			return false;
		}
	}
	else if(l1=='E'){
		if(l2=='D'){
			return true;
		}
		else{
			return false;
		}
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000\n";
	}
	else{
		int k1=0,k2=0;
		int len1=s1.size(),len2=s2.size();
		for(int i=0;i<len1;i++){
			if(s1[i]>='0'&&s1[i]<='9'){
				k1=k1*10+(s1[i]-'0');
			}
			else if(s1[i]>='A'&&s1[i]<='Z'){
				l1=s1[i];
			}
		}
		for(int i=0;i<len2;i++){
			if(s2[i]>='0'&&s2[i]<='9'){
				k2=k2*10+(s2[i]-'0');
			}
			else if(s2[i]>='A'&&s2[i]<='Z'){
				l2=s2[i];
			}
		}
		if(k1!=k2){
			cout<<"1000\n";
		}
		else{
			if(((l1=='A'||l1=='B'||l1=='C')&&(l2=='A'||l2=='B'||l2=='C'))||((l1=='D'||l1=='E')&&(l2=='D'||l2=='E'))){
				if(kkk()){
					cout<<"1111\n";
				}
				else{
					cout<<"1110\n";
				}
			}
			else{
				cout<<"1100\n";
			}
		}
	}
	return 0;
}