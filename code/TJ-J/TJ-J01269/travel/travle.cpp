#include <bits//stdc++.h> 
using namespace std;
int main(){
	freopen("travle.in","r",stdin);
	freopen("travle.out","w",stdout);
	char c1[2],s1[3],c2[2],s2[3];
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	int a[5];
	if(c1==c2){
		a[1]=1;
	}
	else{
		a[1]=0;
	}
	int n=0;
	for(int i=1;i<=2;i++){
		if(s1[i]==s2[1]){
			n++;	
		}
	}
	if(n==2){
		a[2]=1;
	}
	else{
		a[2]=0;
	}
	
	
	cout<<a;
	return 0;
}
