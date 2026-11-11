#include<bits/stdc++.h>
using namespace std;
struct seat{
	int number;
	char word;
};
seat B,D;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	char a[2],b[3],c[2],d[3];
	cin>>a>>b>>c>>d;
	int A,C;
	A=int(a[0]-'0')*10+int(a[1]-'0');
	B.number=int(b[0]-'0')*10+int(b[1]-'0');
	B.word=b[2];
	C=int(c[0]-'0')*10+int(c[1]-'0');
	D.number=int(d[0]-'0')*10+int(d[1]-'0');
	D.word=d[2];
	if(A==C) cout<<1;
	else cout<<0;
	if(B.number==D.number) cout<<1;
	else cout<<0;
	if(B.word>='A'&&B.word<='C'&&D.word>='D'&&D.word<='F'||D.word>='A'&&D.word<='C'&&B.word>='D'&&B.word<='F') cout<<0;
	else cout<<1;
	if(int(B.word-D.word)==1){
		cout<<1;
	}		
	else cout<<0;
	return 0;
} 
