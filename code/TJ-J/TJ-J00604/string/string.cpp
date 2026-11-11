#include <bits/stdc++.h>
using namespace std;
struct st{
	int nu;
	char c;
};
int main(){
	freopen ("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0,num=0;
	cin>>n;
	vector <st> s;	
	s.resize(n);
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		char c;
		cin>>c;		
		num+=x;
		s[i].nu=x;
		s[i].c=c;
	}
    int p1=0,p2=n-1;
	while (num>0){
		int y=min(s[p1].nu,s[p2].nu);
		s[p1].nu-=y;
			s[p2].nu-=y;
			num-=y*2;
			
			
		if (s[p1].c!=s[p2].c){
			cnt+=y;
			
		}
		if(s[p1].nu==0){
			p1++;
		}
		if (s[p2].nu==0){
			p2--;
		}			
		
	}
	cout<<cnt;
	return 0;
} 
