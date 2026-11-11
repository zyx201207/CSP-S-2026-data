#include<bits/stdc++.h>
using namespace std;
inline long long read();

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cout << "Hello world!";
	return 0;
}
inline long long read(){
	long long f = 0, s = 1; char c = getchar();
	while(!isdigit(c)){
		if(c == '-')	s = -1;
		c = getchar();
	}
	while(isdigit(c)){
		f = (f << 3) + (f << 1) + (c ^ 48);
		c = getchar();
	}
	return f * s;
}