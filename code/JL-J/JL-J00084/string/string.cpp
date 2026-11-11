#include<bits/stdc++.h>


using namespace std;

int n; 
char ch, c; 
string s; 

int main () { 
	freopen("string.in", "r", stdin); 
	freopen("string.out", "w", stdout); 
	scanf("%d", &n);  
	for (int i = 1; i <= n; i++) {
		 int x; 
		 scanf("%d", &x); 
		 scanf("%c%c%c", &ch, &c, &ch); 
		 while(x) 
		      --x, s += c; 
	} 
	int ans = 0; 
	int l = s.size(); 
	for (int i = 0; i < l; i++) {
		 if (i > s[l - i - 1]) 
		     break; 
		 if (s[i] != s[l - i - 1]) 
		     ++ans; 
	} 
    printf("%d", ans); 
return 0;} 


