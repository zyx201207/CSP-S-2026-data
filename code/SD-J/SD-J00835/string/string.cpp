#include<bits/stdc++.h>
using namespace std;
long long n, jmc, tyz;
struct r{
	long long m;
	char c;
}a[1145140]; 
vector <int> v;
string s, t;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].m >> a[i].c;
		s += a[i].c;
	}
	for(int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--){
		if(a[i].c != a[j].c){
			if(a[j].m < a[i].m){
				a[j].c = a[i].c;
				jmc += (a[j].m);	
				jmc -= min(tyz, a[j].m);
			//	cout << a[j].m;
			}
			else{
				a[i].c = a[j].c;
				jmc += a[i].m;	
				jmc -= min(tyz, a[i].m);
			}
		}
		if(a[i].m != a[j].m && j - i > 1){
		//	cout << a[j].m;
			jmc += abs(a[i].m - a[j].m);
			tyz += abs(a[i].m - a[j].m);
//			cout << a[i].m << " ";
			a[j].m = a[i].m;
			if(a[j].c == a[j - 1].c){
				j--;
				i++;
				a[j- 1].m += a[j].m;
			}
		}
	}
	cout << jmc;
//	t = reverse(s.begin(), s.end());
//	if(t == s){	
//	}
	return 0;
} 
