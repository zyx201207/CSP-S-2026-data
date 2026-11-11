#include <bits/stdc++.h>
using namespace std;
#define  fin(x)  freopen(x,"r",stdin)
#define  fout(x)  freopen(x,"w",stdout)
string cr,sr,cx,sx;
bool f1,f2,f3,f4;
bool check2(string a,string b){
	if (a[0]!=b[0]) return false;
	if (a[1]!=b[1]) return false;
	return true;
}
bool check3(string a,string b){
	if (a[2]<='C'&&b[2]>='D'||a[2]>='D'&&b[2]<='C') return false;
	return true;
}
bool check4(string a,string b){
	if (a[2]=='F'&&b[2]=='D'||a[2]=='D'&&b[2]=='F') return true;
	if (abs(int(a[2]-b[2]))==1) return true;
	return false;
}
int main()
{
	fin("travel.in");
	fout("travel.out");
	cin>>cr>>sr>>cx>>sx;
	if (cr==cx){
		f1=true;
		if (check2(sr,sx)){
			f2=true;
			if (check3(sr,sx)){
				f3=true;
				if (check4(sr,sx)){
					f4=true;
				}
			}
		}
	}
	cout<<(f1?1:0)<<(f2?1:0)<<(f3?1:0)<<(f4?1:0);
	return 0;
}
