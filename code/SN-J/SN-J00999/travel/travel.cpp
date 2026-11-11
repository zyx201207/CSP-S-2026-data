//AC+ 100 
#include<bits/stdc++.h>
#define fri(x,y) for(int i = x;i <= y;i++)
#define frj(x,y) for(int j = x;j <= y;j++)
#define MAXN 100000 + 10
#define lihaoming 0
using namespace std;
string sr[5];
int qiu_int(char x){
	return x - '0';
}
int qiu_int2(char x){
	return (int)(x - 'A');
}
bool ans[5];
bool qiu_s1[5][5] = {
{0,1,1,0,0},
{1,0,1,0,0},
{1,1,0,0,0},
{0,0,0,0,1},
{0,0,0,1,0}
};
bool qiu_s2[5][5] = {
{0,1,0,0,0},
{1,0,1,0,0},
{0,1,0,0,0},
{0,0,0,0,1},
{0,0,0,1,0}
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	fri(1,4){
		cin>>sr[i];
	}
	int c1,c2,s1,s2;
	c1 = qiu_int(sr[1][0]) * 10
	   + qiu_int(sr[1][1]); 
	c2 = qiu_int(sr[3][0]) * 10
	   + qiu_int(sr[3][1]);
	s1 = qiu_int(sr[2][0]) * 50
	   + qiu_int(sr[2][1]) * 5
	   + qiu_int2(sr[2][2]);
	s2 = qiu_int(sr[4][0]) * 50
	   + qiu_int(sr[4][1]) * 5
	   + qiu_int2(sr[4][2]);
//	cout<<c1<<" "<<s1<<" "<<c2<<" "<<s2<<endl;
	ans[1] = (c1 == c2);
	ans[2] = (s1 / 5 == s2 / 5 && (c1 == c2));
	ans[3] = (qiu_s1[s1 % 5][s2 % 5] && (s1 / 5 == s2 / 5) && (c1 == c2));
	ans[4] = (qiu_s2[s1 % 5][s2 % 5] && (s1 / 5 == s2 / 5) && (c1 == c2));
	fri(1,4){
		cout<<ans[i];
	}
	return lihaoming;
}
