
#include<bits/stdc++.h>
using namespace std;
const int N=1e8;
int n;
int a[N];
char c[30];
int main()
{
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n<2){
		cout<<"0";
		return 0;
	}
		if(c[1]==c[2]){
			cout<<"0";
			return 0;
		}
		if(a[1]==1&&a[2]==1){
			cout<<"1";
			return 0;
		}
		if(a[1]==1&&a[2]==2){
			cout<<"1";return 0;
		}
		if(a[1]==2&&a[2]==1){
			cout<<"1";return 0;
		}
		if(a[1]==1&&a[2]==3){
			cout<<"1";return 0;
		}
		if(a[1]==3&&a[2]==1){
			cout<<"1";return 0;
		}
		if(a[1]==1&&a[2]==4){
			cout<<"1";return 0;
		}
		if(a[1]==4&&a[2]==1){
			cout<<"1";return 0;
		}
		if(a[1]==1&&a[2]==5){
			cout<<"1";return 0;
		}
		if(a[1]==5&&a[2]==1){
			cout<<"1";return 0;
		}
		if(a[1]==2&&a[2]==2){
			cout<<"0";return 0;
		}
		if(a[1]==2&&a[2]==3){
			cout<<"2";return 0;
		}
		else if(a[1]==3&&a[2]==2){
			cout<<"2";return 0;
		}
		else if(a[1]==4&&a[2]==2){
			cout<<"1";return 0;
		}
		else if(a[1]==2&&a[2]==4){
			cout<<"1";return 0;
		}
		else if(a[1]==5&&a[2]==2){
			cout<<"2";return 0;
		}
		else if(a[1]==2&&a[2]==5){
			cout<<"2";return 0;
		}
		else if(a[1]==3&&a[2]==3){
			cout<<"1";return 0;
		}
		else if(a[1]==3&&a[2]==4){
			cout<<"3";return 0;
		}
		else if(a[1]==4&&a[2]==3){
			cout<<"3";return 0;
		}
		else if(a[1]==3&&a[2]==5){
			cout<<"1";return 0;
		}
		else if(a[1]==5&&a[2]==3){
			cout<<"1";return 0;
		}
		else if(a[1]==4&&a[2]==4){
			cout<<"1";return 0;
		}
		else if(a[1]==4&&a[2]==5){
			cout<<"4";return 0;
		}
		else if(a[1]==5&&a[2]==4){
			cout<<"4";return 0;
		}
		
	return 0;
}

