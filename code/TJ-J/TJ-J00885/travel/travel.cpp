//依旧大粪讨+大马量 
#include<iostream>
using namespace std;
int t[10005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>b>>x>>y;
	int cn1,cn2;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C') cn1++;
	if(y[2]=='A'||y[2]=='B'||y[2]=='C') cn1++;
	if(b[2]=='E'||b[2]=='F') cn2++;
	if(y[2]=='E'||y[2]=='F') cn2++;
	t[b[2]]++;
	t[y[2]]++;
	cout<<(a==x?1:0);
	cout<<(a==x&&b[0]+b[1]==y[0]+y[1]?1:0);
	if(a==x&&b[0]+b[1]==y[0]+y[1]){
		if(cn1==2||cn2==2){
			cout<<1;
			if(cn2==2||(t['A']&&t['B'])||(t['B']&&t['C'])) cout<<1;
			else cout<<0;
		}else{
			cout<<0;
			cout<<0;
		}
	}else{
		cout<<0;
		cout<<0;
	}
	return 0;
}

