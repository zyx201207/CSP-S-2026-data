#include<bits/stdc++.h>
using namespace std;int a;
int b;
int c;
int d;
char e;
char f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin >> a >> c >> e >> b >> d >> f;
	if(a==b)cout << 1;
	else{
		for(int i = 1;i <= 4;i++){
			cout << 0;
		}
		return 0;
	}
	if(c==d)cout << 1;
	else{
		for(int i = 1;i <= 3;i++){
			cout << 0;
		}
		return 0;
	}
	if(e>='A'&&e<='C'&&f>='A'&&f<='C')cout << 1;
	else if(e>='D'&&e<='E'&&f>='D'&&f<='E')cout <<1;
	else{
		for(int i =1;i <= 2;i++){
			cout << 0;
		}
		return 0;
	}
	if(e=='C'&&f=='D'){
		cout << 0;
		return 0;
	}
	if(f=='C'&&e=='D'){
		cout << 0;
		return 0;
	}
	if(e==f+1||f==e+1){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
