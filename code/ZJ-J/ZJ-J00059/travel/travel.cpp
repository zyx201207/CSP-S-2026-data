#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<string>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>

using namespace std;
using ll=long long;
using ull=unsigned long long;
using lb=long double;
using pii=pair<int,int>;
using pll=pair<long long,long long>;
using pil=pair<int,long long>;
using pli=pair<long long,int>;

string c1,c2,s1,s2;
bool a,b,c,d;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2)a=1;
	if(a == 1 && s1[0] == s2[0] && s1[1] == s2[1])b=1;
	if(b == 1 && 
	(s1[2] <= 'C' && s2[2] <= 'C') ||
	(s1[2] > 'C' && s2[2] > 'C')) c=1;
	
	if(c == 1){
		if(s1[2] == s2[2]+1 || s1[2] == s2[2]-1)d=1;
	}
	
	cout<<a<<b<<c<<d<<'\n';
	
	return 0;
}