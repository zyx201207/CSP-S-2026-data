#include<iostream>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("traval.out","w",stdout);
	
	char b,d,g;
	int a,c,e,f;
	cin >> a >> b >> c >> d >> e >>f>>g;
	
	
	if(int(a) ==int(e)){
		cout << 1;
		if (int(c)== int(f)){
		cout << 1;
		
		if (d =='A'){
			if(g == 'B'){
			cout <<1<<1;
			}
			else{
				if(g == 'C'){
				cout << 1 << 0;
				}
				else{
					cout << 0 << 0;
				}
			}
		if (d =='D'){
			if(g == 'F'){
			cout <<1<<1;
			}
			else{
					cout << 0 << 0;
				}
			}
		}
		if (d =='C'){
			if(g == 'B'){
			cout <<1<<1;
			}
			else{
				if(g == 'A'){
				cout << 1 << 0;
				}
				else{
					cout << 0 << 0;
				}
			}
		if (d =='F'){
			if(g == 'D'){
			cout <<1<<1;
			}
			else{
					cout << 0 << 0;
				}
			}
		}
		
		}
		
		else{
		cout << 0<<0<<0;}
		
	
		
		
		
	}
	else{
		cout << 0<<0<<0<<0;}
		
	
		
	
	
	return 0;
}
