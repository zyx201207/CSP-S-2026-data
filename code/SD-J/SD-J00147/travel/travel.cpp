#include<bits/stdc++.h>
using namespace std;
string s,c1,c2,s1,s2;
int cn_k=0;
int a[]={1,2,3,4,0,5};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	getline(cin,s);
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]==' '){
			cn_k++; 
			continue;
		}if(cn_k==0){
			c1=c1+s[i];
		}else if(cn_k==1){
			s1=s1+s[i];
		}else if(cn_k==2){
			c2=c2+s[i];
		}else{
			s2=s2+s[i];
		}
	}if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(!(s1[2]<='C')^(s2[2]<='C')){
				if(abs(a[s1[2]-'A']-a[s2[2]-'A'])==1){
					cout<<"1111\n";
				}else{
					cout<<"1110\n";
				}
			}else{
				cout<<"1100\n";
			}
		}else{
			cout<<"1000\n";
		}
	}else{
		cout<<"0000\n";
	}
	return 0;
}

