#include<iostream>
using namespace std;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	long long a,b,cnt=0,n=0;
	string c[200005],d;
	char e;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b;
		cin>>e;
		for(int j=0;j<b;j++){
			c[cnt+j]=e;
		}
		cnt+=b;
	}
	if(cnt%2==0){
		b=cnt/2+1;
	}else{
		b=(cnt+1)/2;
	}for(int i=0;i<b-1;i++){
		if(c[i]!=c[cnt-i-1]){
			n++;
		}
	}
	cout<<n;
	}

