#include <bits/stdc++.h>
using namespace std;
vector<int>a(4);
int main()
{
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	char m,n;
	m=s1[2];
	n=s2[2];
	if(c1==c2){
		a[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a[1]=1;
			if(min(m,n)+1==max(m,n)&&min(m,n)+1!='D'||min(m,n)+2==max(m,n)){
				a[2]=1;	
				if(min(m,n)+1==max(m,n)&&min(m,n)=='A'||min(m,n)=='B')
					a[3]=1;
				else if(min(m,n)+2==max(m,n)&&min(m,n)=='D')
					a[3]=1;
			}
		}
	}
	for(int i=0;i<=3;i++){
		cout<<a[i];
	}
	return 0;
}
