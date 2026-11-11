#include <bits/stdc++.h>
using namespace std;
struct XX{
	string ce;
	string pai;
	char hao;
}r,x;
string s1,s2;
int a[100];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> r.ce >> s1;
	cin >> x.ce >> s2;
	r.pai += s1[0];
	r.pai += s1[1];
	r.hao = s1[2];
	x.pai += s2[0];
	x.pai += s2[1];
	x.hao = s2[2];
	int r1 = 0,r2;
	int x1 = 0,x2;
	if(r.hao == 'A'||r.hao == 'A'||r.hao == 'C'){
		r1 = 1;
	}
	if(x.hao == 'A'||x.hao == 'B'||x.hao == 'C'){
		x1 = 1;
	}
	r2 = r.hao - '0';
	x2 = x.hao - '0';
	if(r.ce == x.ce){
		a[1] = 1;
		if(r.pai == x.pai){
			a[2] = 1;
			if(r1 == x1){
				a[3] = 1;
				if(r2-x2 == 1||r2-x2 == -1){
					a[4] = 1;
				}
			}
		}
	}
	cout << a[1] << a[2] << a[3] << a[4];
	return 0;
} 
