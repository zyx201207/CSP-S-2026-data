#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int read() {
	int f=1,ans=0;
	char ch=getchar();
	if(!isdigit(ch)) {
		if(ch=='-') {
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)) {
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return f*ans;
}
bool qa(string q,string w) {
	if(q==w) {
		return 1;
	} else {
		return 0;
	}
}
bool qb(string q,string w,string e,string r) {
	if(!qa(q,e)) {
		return 0;
	} else {
		for(int i=0; i<2; i++) {
			if(w[i]!=r[i]) {
				return 0;
			}
		}
		return 1;
	}
}
bool qc(string q,string w,string e,string r) {
	if(qb(q,w,e,r)) {
		if(w[1]==r[1]) {
			return 1;
		}
	}
	else{
		return 0;
	}
	
}
bool qd(string q,string w,string e,string r) {
	if(!qc(q,w,e,r)) {
		return 0;
	}
	if(abs(w[2]-'0'-r[2]-'0')==1&&(w[2]!='C'&&r[2]!='D')||(w[2]!='D'&&r[2]!='C')) {
		return 1;
	}

	return 0;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	c1=read(),s1=read(),c2=read(),s2=read();
	cout<<qa(c1,c2)<<qb(c1,s1,c2,s2)<<qc(c1,s1,c2,s2)<<qd(c1,s1,c2,s2);
	return 0;
}
