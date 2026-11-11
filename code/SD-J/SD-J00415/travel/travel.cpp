#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ull=unsigned long long;
using i128=__int128;
using Pii=pair<int,int>;
const int maxN=1e5+10;
bool flag=0;
string c1,s1,c2,s2;
bool work1(){
	if(c1==c2)
	{
//cout<<1<<'\n';
		return 1;
	 } 
//cout<<"1--------\n";
	flag=1;
	return 0;
}
bool work2(){
	if(flag){
//cout<<0<<'\n';
	    return 0;	
	} 
	int t1,t2;
	t1=(s1[0]-'0')*10+(s1[1]-'0');
	t2=(s2[0]-'0')*10+(s2[1]-'0');
//cout<<t1<<' '<<t2<<'\n';
	if(t1==t2) return 1;
	flag=1;
	return 0;
}
bool work3(){
	if(flag) return 0;
	char ch1=s1[2],ch2=s2[2];
	if(ch1>ch2) swap(ch1,ch2);
	if(ch1=='A'&&(ch2=='B'||ch2=='C')) return 1;
	if(ch1=='B'&&ch2=='C') return 1;
	if(ch1=='D'&&ch2=='F') return 1;
	flag=1;
	return 0;
}
bool work4(){
	if(flag) return 0;
	char ch1=s1[2],ch2=s2[2];
	if(ch1>ch2) swap(ch1,ch2);
	if(ch2-ch1==1&&ch1!='C') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<work1();
	cout<<work2();
	cout<<work3();
	cout<<work4();
	return 0;
}

