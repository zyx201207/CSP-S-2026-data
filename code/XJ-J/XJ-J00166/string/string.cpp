#include <bits/stdc++.h>
using namespace std;
string s,re_s;
int n,num;
long long ans;
char c;

string rever(string x){
	string a;
	for (int i = x.size()-1;i >= 0;i--)
	    a += x[i];
	return a; 
}

int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
    cin >> n;
	while (n--){
		cin >> num >> c;	 
		for (int i = 1;i <= num;i++)
		    s += c;
	}	
	re_s = rever(s);
	if (re_s != s){
		if (s.size() % 2 == 0){
			for (int i = 0;i < s.size()/2;i++){
				if (s[i] != s[i+s.size()/2])
				    ans++;
			}
		}else{
			for (int i = 0;i < s.size()/2;i++){
				if (s[i] != s[i+s.size()/2+1])
				    ans++;
			} 
		}
	}
	cout << ans << endl;
} 

