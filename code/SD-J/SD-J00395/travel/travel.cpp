#include<bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

const ll Maxn=1e5+10;

ll c1,c2;
string s1,s2;
ll p1,p2;
char w1,w2;
bool t1,t2,t3,t4;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		t1=1;
		cout<<1;
	}else{
		cout<<0;
	}
	p1=s1[0]*10+s1[1];
	p2=s2[0]*10+s2[1];
	
	if(p1==p2&&t1){
		t2=1;
		cout<<1;
	}else{
		cout<<0;
	}
	
	w1=s1[2];
	w2=s2[2];
	
	if((w1=='A'&&w2=='B')||(w1=='A'&&w2=='C')||(w1=='B'&&w2=='C')||(w1=='D'&&w2=='F')){
		if(t1&&t2){
			t3=1;
			cout<<1;
		}else{
			cout<<0;
		}
	}else if((w1=='B'&&w2=='A')||(w1=='C'&&w2=='A')||(w1=='C'&&w2=='B')||(w1=='F'&&w2=='D')){
		if(t1&&t2){
			t3=1;
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	
	if(abs(int(w1)-int(w2))==1){
		if(t1&&t2&&t3){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	
	return 0; 
}

