#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int m[4];
int main(){
	char a[2],b[3],c[2],d[3];
	cin>>a>>b>>c>>d;
	if(a[1]==c[1]){
		m[0]=1;
		if(b[1]==d[1]){
			m[1]=1;
			if(int(b[2])>='D' && int(d[2])>='D'){
				m[2]=1;
				m[3]=1;
			}if(int(b[2])<='C' && int(d[2])<='C'){
				m[2]=1;
				int x=min(int(b[2]),int(d[2]));
				int y=max(int(b[2]),int(d[2]));
				if(x+1==y){
					m[3]=1;
				}
			}
		}
	}for(int i=0;i<4;i++){
		cout<<m[i];
	}
	return 0;
} 
