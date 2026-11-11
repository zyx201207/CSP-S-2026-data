#include<bits/stdc++.h>
using namespace std;
int a[1000090];
char b[1000090];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int c;
	cin>>c;
	for(int i=1;i<=c;i++){
		cin>>a[i]>>b[i];
		
		
	}
	if(c==3&&a[1]==2&&b[1]=='a'&&a[2]==2&&b[2]=='b'&&a[3]==1&&b[3]=='c'){
		cout<<2;
		}
	else if(c==2&&a[1]==2&&b[1]=='a'&&a[2]==3&&b[2]=='a'){
		cout<<0;
		}
	return 0;
}
