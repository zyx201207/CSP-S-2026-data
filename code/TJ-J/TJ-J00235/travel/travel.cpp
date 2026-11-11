#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
	int cnt = 0;
	int ans = 0;
	for(int i = 0;i < 2;i++){
		if(c1[i] - '0' == c2[i] - '0'){
			ans++;
		}
		if(s1[i] - '0' == s2[i] - '0'){
			cnt++;
		}
	}
	if(ans == 2){
		cout << 1;
		if(cnt == 2){
			cout << 1;
			if((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')){
				cout << 1;
				if((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'C' && s2[2] == 'B')){
					cout << 1;
				}else{
					cout << 0;
				}
			}
			else if((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')){
				cout << 1;
				if((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')){
					cout << 1;
				}else{
					cout << 0;
				}
			}
			else{
				cout << 0 << 0;
			}
	    }else{
	    	cout << 0 << 0 << 0;
		}
	}else{
		cout << 0 << 0 << 0 << 0;
	}
	
	return 0;
}
