#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a=0,b=0,c=0,d=0;
struct where
{
	int room;
	int row;
	char seat;
}r,x;
void find()
{
	if(r.room==x.room)a=1;
	if((a==1)&&(r.row==x.row))b=1;
	if(b==1&&(r.seat=='F'||r.seat=='D')&&(x.seat=='F'||'D'))
		c=1;
	if(b==1&&(r.seat=='A'||r.seat=='B'||r.seat=='C')&&(x.seat=='A'||x.seat=='B'||x.seat=='C'))
		c=1;
	if(c==1&&((r.seat-x.seat==1)||(x.seat-r.seat==1)))
		d=1;
}
int main()
{
	ifstream fin("travel.in");
	ofstream fout("travel.out");
	fin>>c1>>s1>>c2>>s2;
	r.room=c1[1]-'0';
	if(c1[0]!='0')
		r.room+=(c1[0]-'0')*10;
	x.room=c2[1]-'0';
	if(c2[0]!='0')
		x.room+=(c2[0]-'0')*10;
	r.row=s1[1]-'0';
	if(s1[0]!='0')
		r.room+=(s1[0]-'0')*10;
	x.row=s2[1]-'0';
	if(s2[0]!='0')
		x.row+=(s2[0]-'0')*10;
	r.seat=s1[2];
	x.seat=s2[2];
	find();
	fout<<a<<b<<c<<d;
	return 0;
}
