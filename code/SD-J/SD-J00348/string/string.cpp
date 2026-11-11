#include<bits/stdc++.h>
using namespace std;
long long m=0;
char q[1000000000];
inline int readll(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int huiwen(int sum){
	for(int i=0;i<m/2;i++){
		if(q[i]!=q[m-i-1])sum++;
	}
	return sum;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=readll();
	
	
	for(int i=1;i<=n;i++){
		char s;
		long long a=readll();
		
		cin>>s;
		for(int j=m;j<m+a;j++){
			q[j]=s;
		}
		m+=a;
	}
	int l=huiwen(0);
	cout<<l<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
