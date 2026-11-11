#include<bits/stdc++.h>
using namespace std;
int p1 = 0,p2 = 0,p3 = 0,p4 = 0;
void check(string s1,string s2){
    string o1,o2;
    o1 = s1[0] + s1[1];
    o2 = s2[0] + s2[1];
    if(o1 != o2){
        cout << p1 << p2 << p3 << p4 << '\n';
		return;
    }
    p2 = 1;
    char l1 = s1[2];
    char l2 = s2[2];
    if(!((s1[2] == 'F' && l2 == 'D') || (s1[2] == 'D' && l2 == 'F') ||
    (s1[2] == 'C' && l2 == 'B') || (s1[2] == 'C' && l2 == 'A') ||
    (s1[2] == 'B' && l2 == 'C') || (s1[2] == 'A' && l2 == 'C') ||
    (s1[2] == 'B' && l2 == 'A') || (s1[2] == 'A' && l2 == 'B'))){
        cout << p1 << p2 << p3 << p4 << '\n';
		return;
       }
    p3 = 1;
    if(!((l1 == 'F' && l2 == 'D') || (l1 == 'D' && l2 == 'F') ||
    (l1 == 'C' && l2 == 'B') ||  (l1 == 'B' && l2 == 'C') ||
    (l1 == 'B' && l2 == 'A') || (l1 == 'A' && l2 == 'B'))){
        cout << p1 << p2 << p3 << p4 << '\n';
		return;
       }
    p4 = 1;
    cout << p1 << p2 << p3 << p4 << '\n';
    return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a != c){
		cout << p1 << p2 << p3 << p4 << '\n';
		return 0;
	}
    p1 = 1;
    check(b,d);
    return 0;
}


