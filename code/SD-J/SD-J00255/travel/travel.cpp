#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#define endl '\n'
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(nullptr);
	cin.tie(0);
	cout.tie(0);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int n1,n2,n3,n4;
	n1=s1[0]-'0';
	n2=s1[1]-'0';
	n3=s2[0]-'0';
	n4=s2[1]-'0';
	int p1=n1*10+n2;
	int p2=n3*10+n4;
	bool tj1=c1==c2,tj2=(p1==p2)&&tj1,tj3=((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&tj2,tj4=((s1[2]<='C'&&s2[2]<='C'&&abs(int(s1[2]-s2[2]))==1)||(s1[2]>='D'&&s2[2]>='D'))&&tj3;
	cout<<int(tj1);
	cout<<int(tj2);
	cout<<int(tj3);
	cout<<int(tj4);
	return 0;
}
