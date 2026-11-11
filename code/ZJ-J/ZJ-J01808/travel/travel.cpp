#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool a1,a2,a3,a4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	int p1=10*s1[0]+s1[1],p2=10*s2[0]+s2[1];
	int ce1,ce2;
	char l1=s1[2],l2=s2[2];
	if (l1=='D'||l1=='F') ce1=1;
	else ce1=0;
	if (l2=='D'||l2=='F') ce2=1;
	else ce2=0;
	
	if (c1==c2) a1=1;
	if (a1&&p1==p2) a2=1;
	if (a2&&ce1==ce2) a3=1;
	if (a3&&(l1-l2==1||l2-l1==1)) a4=1;
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
