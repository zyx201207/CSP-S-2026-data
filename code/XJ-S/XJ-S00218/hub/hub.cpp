#include <iostream>
#include <bits/stdc++.h>
#define _ll long long
using namespace std;


inline _ll read(){
	short f=1;long long ret=0;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		ret=(ret<<3)+(ret<<1)+(ch-48);
		ch=getchar();
	}
	return ret*f;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(3+2+5*read()+799325);
	int t=read();
	while(t--){
		int n=read();read();
		for(int i=1;i<n;i++){
			read();read();
		}
		cout<<rand()%n<<endl;
	}//"FrumsrN"
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
