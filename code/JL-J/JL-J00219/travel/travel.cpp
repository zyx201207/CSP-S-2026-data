#include <bits/stdc++.h>

using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int n1=s1[0]*10+s1[1],n2=s2[0]*10+s2[1];
	if (c1==c2){
		cout << 1;
		}else {
			cout << 0 << 0 << 0 << 0;
			return 0;
			}
	if (n1==n2){
		cout << 1;
		
		}else {
			cout << 0;
			}
	if ((n1==n2) && ((s1[2]<='C'&&s2[2]<='C') || (s1[2]>='D'&&s2[2]>='D'))){
		cout << 1;
		} else {
			cout << 0 << 0;
			return 0;
			}
	if (s1[2]+1==s2[2] ||s2[2]+1==s1[2]){
		cout << 1;
		} else cout << 0;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	}

