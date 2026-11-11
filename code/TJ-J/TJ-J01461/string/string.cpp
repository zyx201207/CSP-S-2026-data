#include<bits/stdc++.h>
using namespace std;
char hui[10000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	int b,q=0;
	char c;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b>>c;
		for(int d=0;d<b;d++){
			hui[d+q]=c;
		}
		q+=b;
	}
	//判断回文数 
	int cnt=q;
	char s1[10000],s2[10000];
	cnt/=2;
	if(q%2==0){
		for(int aa=0;aa<cnt;aa++){
			s1[aa]=hui[aa];
		}
		int cn=0;
		for(int bb=q-1;bb>=cnt;bb--){
			s2[cn]=hui[bb];
			++cn;
		}
		int if1=1;
		for(int cc=0;cc<=cnt;cc++){
			if(s1[cc]==s2[cc]&&if1==1){
				if1=1;
			}
			else{
				if1=0;
			}
		}
		if(if1){
			cout<<0;
			return 0;
		}
	}
	else{
		for(int aa=0;aa<=cnt;aa++){
			s1[aa]=hui[aa];
		}
		int cn=0;
		for(int bb=q-1;bb>=cnt;bb--){
			s2[cn]=hui[bb];
			++cn;
		}
		int if1=1;
		for(int cc=0;cc<=cnt;cc++){
			if(s1[cc]==s2[cc]&&if1==1){
				if1=1;
			}
			else{
				if1=0;
			}
			
		}
		if(if1){
			cout<<0;
			return 0;
		}
	}
	//不是回文数
	int cntcnt=0;
	if(q%2==1){
		for(int z=0;z<=cnt;z++){
			if(!(s1[z]==s2[z])){
				cntcnt+=1;
			}
		}
	}
	else{
		for(int z=0;z<cnt;z++){
			if(!(s1[z]==s2[z])){
				cntcnt+=1;
			}
		}
	}
	cout<<cntcnt;
	return 0;
}
