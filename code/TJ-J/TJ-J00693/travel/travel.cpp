#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s1,s2;
ll c1,c2;
int a[10000];


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)	cout<<"0000";
	else{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(s1[2]=='A')	a[1]++;
			if(s1[2]=='B')	a[2]++;
			if(s1[2]=='C')	a[3]++;
			if(s1[2]=='D')	a[4]++;
			if(s1[2]=='F')	a[6]++;
			if(s2[2]=='A')	a[1]++;
			if(s2[2]=='B')	a[2]++;
			if(s2[2]=='C')	a[3]++;
			if(s2[2]=='D')	a[4]++;
			if(s2[2]=='F')	a[6]++;
			if(a[1]==1&&a[2]==1||a[1]==1&&a[3]==1||a[2]==1&&a[3]==1||a[4]==1&&a[6]==1){
				cout<<"1";
				if(a[1]==1&&a[2]==1||a[2]==1&&a[3]==1||a[4]==1&&a[6]==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}

	return 0;	 
}
